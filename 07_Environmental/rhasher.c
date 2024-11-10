#include <ctype.h>
#include <errno.h>
#include <rhash.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"

#ifdef USE_READLINE
#include <readline/readline.h>
#endif

#define BUFFER_SIZE 1024
#define MAX_DIGEST_SIZE 64
#define OUTPUT_SIZE 130

typedef enum {
  OK,
  ERROR_MEMORY,
  ERROR_INVALID_ALGORITHM,
  ERROR_HASH,
} ErrorCode;

int read_line(char **buffer, size_t buffer_size) {
#ifdef USE_READLINE
  *buffer = readline(NULL);
  return *buffer != NULL;
#else
  if (buffer == NULL || buffer_size <= 0) {
    return ERROR_MEMORY;
  }

  return getline(buffer, &buffer_size, stdin) != -1;
#endif
}

int eval_input(char *buffer, size_t buffer_size, char *digest, char *output) {
  char *hash_algorithm = strtok(buffer, " ");
  char *message = strtok(NULL, " ");

  if (hash_algorithm == NULL || message == NULL) {
    fprintf(stderr, "Invalid input\n");
    return ERROR_INVALID_ALGORITHM;
  }

  size_t base_type;
  if (hash_algorithm[0] >= 'a' && hash_algorithm[0] <= 'z') {
    base_type = RHPR_BASE64;
  } else {
    base_type = RHPR_HEX;
  }

  for (int i = 0; hash_algorithm[i]; i++) {
    hash_algorithm[i] = tolower(hash_algorithm[i]);
  }

  size_t hash_type;
  if (strncmp(hash_algorithm, "md5", strlen("md5")) == 0) {
    hash_type = RHASH_MD5;
  } else if (strncmp(hash_algorithm, "sha1", strlen("sha1")) == 0) {
    hash_type = RHASH_SHA1;
  } else if (strncmp(hash_algorithm, "tth", strlen("tth")) == 0) {
    hash_type = RHASH_TTH;
  } else {
    fprintf(stderr, "Unknown algorithm: %s\n", hash_algorithm);
    return ERROR_INVALID_ALGORITHM;
  }

  int res;
  message[strcspn(message, "\n")] = 0;
  if (message[0] == '\"') {
    message++;
    message[strlen(message) - 1] = '\0';
    res = rhash_msg(hash_type, message, strlen(message), digest);
  } else {
    res = rhash_file(hash_type, message, digest);
  }

  if (res < 0) {
    fprintf(stderr, "LibRHash error: %s: %s\n", message, strerror(errno));
    return ERROR_HASH;
  }

  rhash_print_bytes(output, digest, rhash_get_digest_size(hash_type),
                    (base_type | RHPR_UPPERCASE));

  printf("%s\n", output);

  return 0;
}

int main(void) {
  char *buffer = NULL;
  size_t buffer_size = BUFFER_SIZE;
  char digest[MAX_DIGEST_SIZE];
  char output[OUTPUT_SIZE];

  rhash_library_init();

#ifndef USE_READLINE
  buffer = (char *)malloc(buffer_size);
  if (buffer == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return ERROR_MEMORY;
  }
#endif

  while (read_line(&buffer, buffer_size)) {
    eval_input(buffer, buffer_size, digest, output);
#ifdef USE_READLINE
    free(buffer);
#endif
  }
  return 0;
}
