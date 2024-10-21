#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ERROR_MSG_LENGTH 256
#define MAX_RESULT_LENGTH 8192

#define MAX_GROUPS 10
#define MAX_SUBSTITUTIONS 100

void handle_regerror(int errcode, regex_t *regex) {
  char error_msg[MAX_ERROR_MSG_LENGTH];
  regerror(errcode, regex, error_msg, sizeof(error_msg));
  fprintf(stderr, "Regex error: %s\n", error_msg);
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <regexp> <substitution> <string>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  const char *regexp = argv[1];
  const char *substitution = argv[2];
  const char *string = argv[3];

  regex_t regex;

  int ret = regcomp(&regex, regexp, REG_EXTENDED);
  if (ret != 0) {
    handle_regerror(ret, &regex);
    exit(EXIT_FAILURE);
  }

  regmatch_t matches[MAX_GROUPS];
  ret = regexec(&regex, string, MAX_GROUPS, matches, 0);
  if (ret == REG_NOMATCH) {
    printf("%s\n", string);
    regfree(&regex);
    return EXIT_SUCCESS;
  }

  if (ret) {
    handle_regerror(ret, &regex);
    regfree(&regex);
    exit(EXIT_FAILURE);
  }

  char result[MAX_RESULT_LENGTH] = {0};

  size_t subst_pos = 0;
  size_t res_pos = 0;

  while (substitution[subst_pos]) {
    if (substitution[subst_pos] == '\\') {
      subst_pos += 1;
      if (substitution[subst_pos] >= '1' && substitution[subst_pos] <= '9') {
        int match_index = substitution[subst_pos] - '0';

        if (match_index >= MAX_GROUPS) {
          printf("Too many groups\n");
          regfree(&regex);
          exit(EXIT_FAILURE);
        }

        if (matches[match_index].rm_so == -1) {
          printf("Group not found\n");
          regfree(&regex);
          exit(EXIT_FAILURE);
        }

        size_t substitution_length =
            matches[match_index].rm_eo - matches[match_index].rm_so;

        if (substitution_length > (MAX_RESULT_LENGTH - res_pos)) {
          printf("Too large result\n");
          regfree(&regex);
          exit(EXIT_FAILURE);
        }

        strncpy(result + res_pos, string + matches[match_index].rm_so,
                substitution_length);
        res_pos += substitution_length;
      }
    } else if (substitution[subst_pos] == '\\') {
      result[res_pos++] = '\\';
    } else {
      result[res_pos++] = substitution[subst_pos];
    }
    subst_pos++;
  }

  printf("%s\n", result);
  regfree(&regex);

  return EXIT_SUCCESS;
}
