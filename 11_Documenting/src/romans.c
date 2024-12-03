#include "romans.h"
#include <string.h>

/** @file romans.c
 * Handle manipulation with Roman numerals:
 * - convert integer to Roman numeral
 * - convert Roman numeral to integer
 * Works only for numbers from 1 to 100.
 */

/**
 * @brief Roman numerals from 1 to 100
 */
const char *roman_numerals[] = {
    "I",       "II",     "III",     "IV",       "V",      "VI",      "VII",
    "VIII",    "IX",     "X",       "XI",       "XII",    "XIII",    "XIV",
    "XV",      "XVI",    "XVII",    "XVIII",    "XIX",    "XX",      "XXI",
    "XXII",    "XXIII",  "XXIV",    "XXV",      "XXVI",   "XXVII",   "XXVIII",
    "XXIX",    "XXX",    "XXXI",    "XXXII",    "XXXIII", "XXXIV",   "XXXV",
    "XXXVI",   "XXXVII", "XXXVIII", "XXXIX",    "XL",     "XLI",     "XLII",
    "XLIII",   "XLIV",   "XLV",     "XLVI",     "XLVII",  "XLVIII",  "XLIX",
    "L",       "LI",     "LII",     "LIII",     "LIV",    "LV",      "LVI",
    "LVII",    "LVIII",  "LIX",     "LX",       "LXI",    "LXII",    "LXIII",
    "LXIV",    "LXV",    "LXVI",    "LXVII",    "LXVIII", "LXIX",    "LXX",
    "LXXI",    "LXXII",  "LXXIII",  "LXXIV",    "LXXV",   "LXXVI",   "LXXVII",
    "LXXVIII", "LXXIX",  "LXXX",    "LXXXI",    "LXXXII", "LXXXIII", "LXXXIV",
    "LXXXV",   "LXXXVI", "LXXXVII", "LXXXVIII", "LXXXIX", "XC",      "XCI",
    "XCII",    "XCIII",  "XCIV",    "XCV",      "XCVI",   "XCVII",   "XCVIII",
    "XCIX",    "C"};

/**
 * @brief Convert integer to Roman numeral
 * @param number - integer number
 * @return Corresponding Roman numeral (string)
 */
const char *integer_to_roman(int number) { return roman_numerals[number - 1]; }

/**
 * @brief Convert Roman numeral to integer
 * @param roman - Roman numeral (string)
 * @return Corresponding integer number
 */
int roman_to_integer(const char *roman) {
  for (int i = 0; i < sizeof(roman_numerals) / sizeof(roman_numerals[0]); i++) {
    if (strcmp(roman, roman_numerals[i]) == 0) {
      return i + 1;
    }
  }

  return -1;
}
