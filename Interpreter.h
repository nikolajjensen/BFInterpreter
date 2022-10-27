#pragma once
#include <map>
#include <string>
#include "Execution.h"

/**
 * @brief Namespace for the BF Interpreter.
 * 
 * Code used in implementation has been translated - and substantially 
 * adjusted to take advantage of OOP - from the base project produced 
 * by 'Nikolaj Banke Jensen' for the PLD Scala coursework.
 * 
 * Many prominent changes have been made, such as reduction of 
 * recursive function use, and incorporation of the pass-by-reference Execution object.
 */
namespace Interpreter {

  /**
   * @brief Helper function to make a 'right'-jump to a matching bracket in the BF code.
   * 
   * Returns the program counter corresponding to the index just after the matching ']'.
   * 
   * In case there is no matching bracket, the length of the program will be returned.
   * 
   * @param program The program in which to find a matching bracket.
   * @param program_ctr The initial program counter from which to start searching for a matching bracket.
   * @param level Should be called with 0. Used to track matching brackets using recursive calls of the function.
   * @return The program counter corresponding to the entry in the program just after the closing bracket.
   */
  int jump_right(const std::string& program, int program_ctr, int level = 0);

  /**
   * @brief Helper function to make a 'left'-jump to a matching bracket in the BF code.
   * 
   * Returns the program counter corresponding to the index just after the matching '['.
   * 
   * In case there is no matching bracket, -1 will be returned.
   * 
   * @param program The program in which to find a matching bracket.
   * @param program_ctr The initial program counter from which to start searching for a matching bracket.
   * @param level Should be called with 0. Used to track matching brackets using recursive calls of the function.
   * @return The program counter corresponding to the entry in the program just after the closing bracket.
   */
  int jump_left(const std::string& program, int program_ctr, int level = 0);

  /**
   * @brief Create a bracket lookup table for use in execution.
   * 
   * @param execution The Execution whose bracket_table will be updated.
   */
  void create_bracket_table(Execution &execution);

  /**
   * @brief Process a single character of the BF program.
   * 
   * The character to be processed is defined as the character at 
   * program[program_ctr], where program an program_ctr are extracted from the Execution object.
   * 
   * @param execution The Execution to progress.
   */
  void progress(Execution &execution);

  /**
   * @brief Executes a BF program with empty memory, and both program_ctr and memory_ctr equal to 0.
   * 
   * @param program The program to execute.
   * @return Execution The Execution after program is finished.
   */
  Execution execute(const std::string& program);

  /**
   * @brief Executes a BF program with both program_ctr and memory_ctr equal to 0, but using the provided memory as a starting point.
   * 
   * @param program The program to execute.
   * @param memory The initial memory from which to execute the program.
   * @return Execution The Execution after program is finished.
   */
  Execution execute(const std::string& program, std::map<unsigned int, int>& memory);
};