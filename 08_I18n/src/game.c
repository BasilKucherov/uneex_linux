#include <libintl.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _(STRING) gettext(STRING)

typedef enum { YES, NO, INVALID } Answer;

Answer get_answer() {
  size_t answer_size = 4;
  char *answer = (char *)malloc(answer_size);

  while (getline(&answer, &answer_size, stdin) != -1) {
    if (strncmp(answer, _("yes"), strlen(answer) - 1) == 0) {
      return YES;
    } else if (strncmp(answer, _("no"), strlen(answer) - 1) == 0) {
      return NO;
    } else {
      printf(_("Invalid answer, please enter yes or no\n"));
    }
  }

  return INVALID;
}

int game() {
  printf(_("Let's play a game!\n"));
  printf(_("Think of a number between 1 and 100\n"));

  int low = 1;
  int high = 100;
  int guess = (low + high) / 2;

  while (low != high) {
    printf(_("Is your number bigger than %d? (yes/no)\n"), guess);
    Answer answer = get_answer();

    if (answer == YES) {
      low = guess + 1;
    } else if (answer == NO) {
      high = guess;
    } else if (answer == INVALID) {
      return 0;
    }

    guess = (low + high) / 2;
  }

  printf(_("Your number is %d!\n"), guess);
  printf(_("Do you want to play again? (yes/no)\n"));

  return get_answer() == YES;
}

int main() {
  setlocale(LC_ALL, "");
  bindtextdomain("game", ".");
  textdomain("game");

  while (game())
    ;

  return 0;
}
