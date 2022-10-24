#pragma once
#include <string>
#include <map>

/**
 * @brief Namespace for methods which test execution of various parts of the interpreter.
 */
namespace Tests {

  /**
   * @brief Namespace for methods that are repeatedly used int testing various parts of the interpreter.
   */
  namespace helpers {

    /**
     * @brief Tests the 'jump_right' method of the Interpreter.
     * 
     * @param program The program to jump within.
     * @param initial_program_ctr The initial program counter.
     * @param expected_program_ctr The expected program counter after a jump.
     * @return true If the expected program counter is indeed equal to the program counter produced by the jump.
     * @return false If the expected program counter is not equal to the program counter produced by the jump.
     */
    bool jump_right(const std::string& program, int initial_program_ctr, int expected_program_ctr);

    /**
     * @brief Tests the 'jump_left' method of the Interpreter.
     * 
     * @param program The program to jump within.
     * @param initial_program_ctr The initial program counter.
     * @param expected_program_ctr The expected program counter after a jump.
     * @return true If the expected program counter is indeed equal to the program counter produced by the jump.
     * @return false If the expected program counter is not equal to the program counter produced by the jump.
     */
    bool jump_left(const std::string& program, int initial_program_ctr, int expected_program_ctr);

    /**
     * @brief Runs the given program, with the given initial memory.
     * 
     * This is handy for testing smaller parts of a program, to see if the Interpreter behaves correctly.
     * 
     * @param program The program to test.
     * @param initial_memory The initial memory to start execution with.
     * @param expected_memory The expected memory after execution.
     * @return true If the contents of the expected memory is indeed equal to the contents of the memory after execution (by Utils::map_compare).
     * @return false If the contents of the expected memory is not equal to the contents of the memory after execution (by Utils::map_compare).
     */
    bool run(const std::string& program, std::map<unsigned int, int>& initial_memory, const std::map<unsigned int, int>& expected_memory);
  };

  /**
   * @brief Runs all tests for 'jump_right'.
   * 
   * @return true If all tests pass.
   * @return false If any tests fail.
   */
  bool run_jump_right_tests();

  /**
   * @brief Runs all tests for 'jump_left'.
   * 
   * @return true If all tests pass.
   * @return false If any tests fail.
   */
  bool run_jump_left_tests();

  /**
   * @brief Runs all tests for 'run' with some initial memory.
   * 
   * @return true If all tests pass.
   * @return false If any tests fail.
   */
  bool run_simple_programs_with_memory();


  /**
   * @brief Runs all tests.
   * 
   * @return true If all tests pass.
   * @return false If any tests fail.
   */
  bool run_all();
};