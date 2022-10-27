#pragma once
#include <string>
#include <iostream>
#include <map>

/**
 * @brief Model encapsulating the midpoint or end of execution of a BF program.
 */
struct Execution {
  std::string program;
  int program_ctr;
  unsigned int memory_ptr;
  std::map<unsigned int, int> memory;
  std::map<int, int> bracket_table;

  /**
   * @brief Construct a new Execution object
   * 
   * @param program_in The program to execute.
   */
  Execution(const std::string& program_in);

  /**
   * @brief Construct a new Execution object
   * 
   * @param program_in The program to execute.
   * @param memory_in The memory to execute from.
   */
  Execution(const std::string& program_in, std::map<unsigned int, int>& memory_in);

  /**
   * @brief Get the value of memory at the key.
   * 
   * If there is no entry for the key in memory, 0 will be return.
   * 
   * @param key The key from which to get the value.
   * @return int The contents fo memory at the key.
   */
  int getMemory(unsigned int& key);

  /**
   * @brief Set the value of memory at the key.
   * 
   * @param key The key for which the value should be updated.
   * @param value The new contents.
   */
  void setMemory(unsigned int& key, int value);

  /**
   * @brief Helper function to pretty-print an Execution object to an ostream.
   * 
   * Helps for debugging purposes.
   * 
   * @param os The std::ostream to append to.
   * @param execution The Execution to print.
   * @return std::ostream& The updated std::ostream.
   */
  friend std::ostream& operator<<(std::ostream& os, const Execution& execution) {
    os << "[Program counter: " << execution.program_ctr << ", Memory pointer: " << execution.memory_ptr << ", Memory: {";
    for(const auto& memory_entry : execution.memory) {
      os << "(" << memory_entry.first << ": " << memory_entry.second << ")";
    }
    os << "}]";

    return os;
  }
};