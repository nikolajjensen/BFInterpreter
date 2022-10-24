#include <map>
#include "Utils.h"

/**
 * This code snippet was produced by Stack Overflow user 'kdt'.
 * (22/10/2022) https://stackoverflow.com/questions/874134/find-out-if-string-ends-with-another-string-in-c
 */
bool Utils::string_has_ending(const std::string& str, const std::string& ending) {
  if(str.length() >= ending.length()) {
    return (0 == str.compare(str.length() - ending.length(), ending.length(), ending));
  } else {
    return false;
  }
}

std::string Utils::load(const std::string& filename) {
  std::ifstream f(filename);
  std::stringstream ss;
  ss << f.rdbuf();
  return ss.str();
}

/**
 * This code snippet was produced by Stack Overflow user 'Sebastian Mach'.
 * (22/10/2022) https://stackoverflow.com/questions/8473009/how-to-efficiently-compare-two-maps-of-strings-in-c-only-for-a-subset-of-the-k
 */
template <typename Map>
bool Utils::map_compare(Map const &lhs, Map const &rhs) {
  return lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

// Explicit template instantiation
template bool Utils::map_compare<std::map<unsigned int, int>>(std::map<unsigned int, int> const &lhs, std::map<unsigned int, int> const &rhs);