#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <fcntl.h>

typedef enum {
  SUCCESS,
  E_WRONG_ARGUMENTS,
  E_OPEN_SOURCE,
  E_OPEN_DESTINATION,
  E_WRITE,
  E_READ,
  E_CLOSE
} ErrorCode;

const char *error_message(ErrorCode error_code) {
  switch (error_code) {
  case SUCCESS:
    return "Success";
  case E_WRONG_ARGUMENTS:
    return "Wrong arguments";
  case E_OPEN_SOURCE:
    return "Failed to open source file";
  case E_OPEN_DESTINATION:
    return "Failed to open destination file";
  case E_WRITE:
    return "Failed to write to destination file";
  case E_READ:
    return "Failed to read from source file";
  case E_CLOSE:
    return "Failed to close file";
  }
}

// cp source destination
int copy_file(int source_fd, int destination_fd) {
  char buffer[4096] = {0};
  ssize_t bytes_read = 0;

  while ((bytes_read = read(source_fd, buffer, sizeof(buffer))) > 0) {
    ssize_t bytes_written = 0;
    while (bytes_written < bytes_read) {
      ssize_t bytes_written_now = write(destination_fd, buffer + bytes_written,
                                        bytes_read - bytes_written);
      if (bytes_written_now < 0) {
        return E_WRITE;
      }
      bytes_written += bytes_written_now;
    }

    if (bytes_written != bytes_read) {
      return E_WRITE;
    }
  }

  if (bytes_read < 0) {
    return E_READ;
  }

  return SUCCESS;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
    exit(E_WRONG_ARGUMENTS);
  }

  const char *source = argv[1];
  const char *destination = argv[2];

  int source_fd = open(source, O_RDONLY);
  if (source_fd < 0) {
    fprintf(stderr, "Error: %s\n", error_message(E_OPEN_SOURCE));
    exit(E_OPEN_SOURCE);
  }

  int destination_fd = open(destination, O_WRONLY | O_CREAT | O_TRUNC, 0666);
  if (destination_fd < 0) {
    close(source_fd);
    fprintf(stderr, "Error: %s\n", error_message(E_OPEN_DESTINATION));
    exit(E_OPEN_DESTINATION);
  }

  ErrorCode error_code = copy_file(source_fd, destination_fd);

  if (error_code != SUCCESS) {
    close(source_fd);
    close(destination_fd);
    remove(destination);
    fprintf(stderr, "Error: %s\n", error_message(error_code));
    exit(error_code);
  }

  close(source_fd);
  close(destination_fd);

  remove(source);

  return 0;
}
