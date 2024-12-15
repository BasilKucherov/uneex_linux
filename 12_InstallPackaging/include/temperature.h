/**
 * @file temperature.h
 * @brief Temperature conversion utilities and unit definitions
 * @author Your Name
 * @date YYYY-MM-DD
 */

#ifndef TEMPERATURE_H
#define TEMPERATURE_H

/**
 * @brief Enumeration for temperature units
 */
enum Unit { 
    UNKNOWN,    /**< Unknown temperature unit */
    CELSIUS,    /**< Celsius temperature unit */
    KELVIN,     /**< Kelvin temperature unit */
    FAHRENHEIT  /**< Fahrenheit temperature unit */
};

/**
 * @brief Converts a Unit enum to its string representation
 * @param unit The temperature unit to convert
 * @return String representation of the temperature unit
 */
char *unit_to_string(enum Unit unit);

/**
 * @brief Converts a character to its corresponding Unit enum
 * @param unit Character representing the temperature unit ('C', 'K', or 'F')
 * @return Corresponding Unit enum value
 */
enum Unit char_to_unit(char unit);

/**
 * @brief Converts temperature from Celsius to Kelvin
 * @param celsius Temperature in Celsius
 * @return Temperature in Kelvin
 */
double celsius_to_kelvin(double celsius);

/**
 * @brief Converts temperature from Kelvin to Celsius
 * @param kelvin Temperature in Kelvin
 * @return Temperature in Celsius
 */
double kelvin_to_celsius(double kelvin);

/**
 * @brief Converts temperature from Fahrenheit to Celsius
 * @param fahrenheit Temperature in Fahrenheit
 * @return Temperature in Celsius
 */
double fahrenheit_to_celsius(double fahrenheit);

/**
 * @brief Converts temperature from Celsius to Fahrenheit
 * @param celsius Temperature in Celsius
 * @return Temperature in Fahrenheit
 */
double celsius_to_fahrenheit(double celsius);

#endif
