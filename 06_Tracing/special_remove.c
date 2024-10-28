#include <dlfcn.h>
#include <stdio.h>
#include <string.h>

int remove(const char *filename) {
  printf("My special remove(%s)\n", filename);
  if (strstr(filename, "PROTECTED")) {
    return 0;
  }

  int (*original_remove)(const char *) = dlsym(RTLD_NEXT, "remove");
  if (!original_remove) {
    fprintf(stderr, "Error: %s\n", dlerror());
    return -1;
  }

  return original_remove(filename);
}
