#pragma once
#include <string>
#include <fstream>
#include <sstream>

/**
 * @brief Various utility functions used throughout the application.
 * 
 * Includes functionality for loading files and working with maps.
 */
namespace Utils {
  /**
   * @brief Check if the string ends with the provided string.
   * 
   * @param str String to check.
   * @param ending Ending to match to str.
   * @return true If the provided string ends with the ending.
   * @return false If the provided string does not end with the ending.
   */
  bool string_has_ending(const std::string& str, const std::string& ending);

  /**
   * @brief Loads the file content as a std::string.
   * 
   * Returns an empty string if the file is not found, or could not be opened.
   * 
   * @param filename Name and path of the file to open.
   * @return std::string The contents of the file.
   */
  std::string load(const std::string& filename);

  /**
   * @brief Compares the contents of the two maps using complete equality.
   * 
   * @tparam Map Map template.
   * @param lhs One map to compare.
   * @param rhs Another map to compare.
   * @return true If the two maps are completely equal.
   * @return false If the two maps are not completely equal.
   */
  template <typename Map>
  bool map_compare(Map const &lhs, Map const &rhs);
};