#include <check.h>
#include "temperature.h"
#include "constants.h"

#suite Temperature
#tcase UnitConversion

#test unit_to_string_test
    ck_assert_str_eq(unit_to_string(CELSIUS), "Celsius");
    ck_assert_str_eq(unit_to_string(KELVIN), "Kelvin");
    ck_assert_str_eq(unit_to_string(FAHRENHEIT), "Fahrenheit");
    ck_assert_str_eq(unit_to_string(UNKNOWN), "Unknown");

#test char_to_unit_test
    ck_assert_int_eq(char_to_unit('C'), CELSIUS);
    ck_assert_int_eq(char_to_unit('c'), CELSIUS);
    ck_assert_int_eq(char_to_unit('K'), KELVIN);
    ck_assert_int_eq(char_to_unit('k'), KELVIN);
    ck_assert_int_eq(char_to_unit('F'), FAHRENHEIT);
    ck_assert_int_eq(char_to_unit('f'), FAHRENHEIT);
    ck_assert_int_eq(char_to_unit('X'), UNKNOWN);

#tcase TemperatureConversion

#test celsius_to_kelvin_test
    ck_assert_double_eq_tol(celsius_to_kelvin(0.0), 273.15, 0.001);
    ck_assert_double_eq_tol(celsius_to_kelvin(-273.15), 0.0, 0.001);
    ck_assert_double_eq_tol(celsius_to_kelvin(100.0), 373.15, 0.001);

#test kelvin_to_celsius_test
    ck_assert_double_eq_tol(kelvin_to_celsius(273.15), 0.0, 0.001);
    ck_assert_double_eq_tol(kelvin_to_celsius(0.0), -273.15, 0.001);
    ck_assert_double_eq_tol(kelvin_to_celsius(373.15), 100.0, 0.001);

#test fahrenheit_to_celsius_test
    ck_assert_double_eq_tol(fahrenheit_to_celsius(32.0), 0.0, 0.001);
    ck_assert_double_eq_tol(fahrenheit_to_celsius(212.0), 100.0, 0.001);
    ck_assert_double_eq_tol(fahrenheit_to_celsius(-40.0), -40.0, 0.001);

#test celsius_to_fahrenheit_test
    ck_assert_double_eq_tol(celsius_to_fahrenheit(0.0), 32.0, 0.001);
    ck_assert_double_eq_tol(celsius_to_fahrenheit(100.0), 212.0, 0.001);
    ck_assert_double_eq_tol(celsius_to_fahrenheit(-40.0), -40.0, 0.001);