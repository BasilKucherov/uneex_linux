/** @mainpage GameInternationalRoman
 * @copydetails game
 */
/** @page game GameInternationalRoman
 * This is free and unencumbered software released into the public domain.
 *
 * This package contains a simple game that guesses a number between 1 and
 * 100.
 * The user can choose to use Roman numeral system or decimal.
 *
 * - r - option - use Roman numeral system
 * - h - option - print help message
 *
 * @section AUTHORS
 * - basilkucherov@gmail.com

 */

#include "romans.h"
#include <argp.h>
#include <libintl.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** @file game.c
 * Main game logic:
 * - Handle user input
 * - Guess a number between 1 and 100
 * - Use Roman numeral system if enabled
 */

#define _(STRING) gettext(STRING) /**< Get translated string */

typedef enum { YES, NO, INVALID } Answer;

/** @brief Command line arguments */
struct arguments {
  int romans; /**< Use Roman numeral system */
  int help;   /**< Print help message */
};

/**
 * @brief Get user answer
 * @return YES if user answered yes, NO if no, INVALID if invalid answer
 */
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

/**
 * @brief Main game loop
 * @param use_romans - use Roman numeral system if true, decimal otherwise
 * @return 1 if user wants to play again, 0 otherwise
 */
int game(const int use_romans) {
  printf(_("Let's play a game!\n"));
  if (use_romans) {
    printf(_("Think of a number between %s and %s\n"), integer_to_roman(1),
           integer_to_roman(100));
  } else {
    printf(_("Think of a number between 1 and 100\n"));
  }

  int low = 1;
  int high = 100;
  int guess = (low + high) / 2;

  while (low != high) {
    if (use_romans) {
      printf(_("Is your number bigger than %s? (yes/no)\n"),
             integer_to_roman(guess));
    } else {
      printf(_("Is your number bigger than %d? (yes/no)\n"), guess);
    }
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

  if (use_romans) {
    printf(_("Your number is %s!\n"), integer_to_roman(guess));
  } else {
    printf(_("Your number is %d!\n"), guess);
  }

  printf(_("Do you want to play again? (yes/no)\n"));

  return get_answer() == YES;
}

/**
 * @brief Print help message
 */
void print_help() {
  printf(_("Usage: game [OPTION...]\n"));
  printf(_("Guess a number between 1 and 100\n"));
  printf(_("-r, --roman                Use Roman numeral system\n"));
  printf(_("-h, --help                 Give this help list\n"));
}

/**
 * @brief Parse command line arguments
 * @param argc - number of arguments
 * @param argv - array of arguments
 * @return struct with parsed arguments
 */
struct arguments parse_args(int argc, char **argv) {
  struct arguments arguments;
  arguments.romans = 0;
  arguments.help = 0;

  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-r") == 0 || strcmp(argv[i], "--roman") == 0) {
      arguments.romans = 1;
    } else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
      arguments.help = 1;
    } else {
      printf(_("Invalid option: %s\n"), argv[i]);
      arguments.help = 1;
    }
  }

  return arguments;
}

/**
 * @brief Main function
 * @param argc - number of arguments
 * @param argv - array of arguments
 * @return 0 if success, 1 otherwise
 */
int main(int argc, char **argv) {
  setlocale(LC_ALL, "");
  bindtextdomain("game", ".");
  textdomain("game");

  struct arguments arguments = parse_args(argc, argv);

  if (arguments.help) {
    print_help();
    return 0;
  }

  if (arguments.romans) {
    printf(_("Roman numeral system is enabled\n"));
  } else {
    printf(_("Decimal system is enabled\n"));
  }

  while (game(arguments.romans))
    ;

  return 0;
}
