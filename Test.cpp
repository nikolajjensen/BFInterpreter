#include <iostream>
#include "Test.h"
#include "Execution.h"
#include "Interpreter.h"
#include "Utils.h"

bool Tests::helpers::jump_right(const std::string& program, int initial_program_ctr, int expected_program_ctr) {
  Execution e(program);
  e.program_ctr = initial_program_ctr;
  Interpreter::jump_right(e);
  bool success = (e.program_ctr == expected_program_ctr);
  std::cout << program << " => " << e.program_ctr << " == " << expected_program_ctr << " ? " << (success ? "PASS" : "FAIL") << std::endl;
  return success;
}

bool Tests::helpers::jump_left(const std::string& program, int initial_program_ctr, int expected_program_ctr) {
  Execution e(program);
  e.program_ctr = initial_program_ctr;
  Interpreter::jump_left(e);
  bool success = (e.program_ctr == expected_program_ctr);
  std::cout << program << " => " << e.program_ctr << " == " << expected_program_ctr << " ? " << (success ? "PASS" : "FAIL") << std::endl;
  return success;
}

bool Tests::helpers::run(const std::string& program, std::map<unsigned int, int>& initial_memory, const std::map<unsigned int, int>& expected_memory) {
  std::cout << program << ", {";
  
  for(const auto& memory_entry : initial_memory) {
    std::cout << "(" << memory_entry.first << ": " << memory_entry.second << ")";
  }
  std::cout << "}";

  Execution result = Interpreter::execute(program, initial_memory);
  bool success = Utils::map_compare(result.memory, expected_memory);


  std::cout << " => {";
  for(const auto& memory_entry : result.memory) {
    std::cout << "(" << memory_entry.first << ": " << memory_entry.second << ")";
  }
  std::cout << "} == {";
  for(const auto& memory_entry : expected_memory) {
    std::cout << "(" << memory_entry.first << ": " << memory_entry.second << ")";
  }
  std::cout << "} ? " << (success ? "PASS" : "FAIL") << std::endl;

  return success;
}


bool Tests::run_jump_right_tests() {
  std::cout << "Testing jump_right:" << std::endl;

  bool success = true;

  success = success && helpers::jump_right("--[..+>--],>,++", 3, 10);
  success = success && helpers::jump_right("--[..[+>]--],>,++", 3, 12);
  success = success && helpers::jump_right("--[..[[-]+>[.]]--],>,++", 3, 18);
  success = success && helpers::jump_right("--[..[[-]+>[.]]--,>,++", 3, 22);
  success = success && helpers::jump_right("**********", 7, 10);
  success = success && helpers::jump_right("+++++[->++++++++++<]>--<+++[->>++++++++++<<]>>++<<----------[+>.>.<+<]", 6, 20);
  success = success && helpers::jump_right("[xxxxxx]xxx", 1, 8);
  success = success && helpers::jump_right("[xx[x]x]xxx", 1, 8);
  success = success && helpers::jump_right("[xx[xxx]xxx", 1, 11);
  success = success && helpers::jump_right("[x[][]x]xxx", 1, 8);

  std::cout << "======= " << (success ? "PASS" : "FAIL") << " =======\n" << std::endl;

  return success;
}

bool Tests::run_jump_left_tests() {
  std::cout << "Testing jump_left:" << std::endl;

  bool success = true;

  success = success && helpers::jump_left("--[..+>--],>,++", 8, 3);
  success = success && helpers::jump_left("[******]***", 7, -1);
  success = success && helpers::jump_left("**********", 7, -1);
  success = success && helpers::jump_left("+++++[->++++++++++<]>--<+++[->>++++++++++<<]>>++<<----------[+>.>.<+<]", 18, 6);
  success = success && helpers::jump_left("[xxxxxx]xxx", 6, 1);
  success = success && helpers::jump_left("[xxxxxx]xxx", 7, -1);
  success = success && helpers::jump_left("[x[][]x]xxx", 6, 1);

  std::cout << "======= " << (success ? "PASS" : "FAIL") << " =======\n" << std::endl;

  return success;
}

bool Tests::run_simple_programs_with_memory() {
  std::cout << "Testing small programs with memory:" << std::endl;

  bool success = true;

  {
    std::map<unsigned int, int> init_mem({{0, 100}});
    std::map<unsigned int, int> expected_mem({{0, 0}});
    success = success && helpers::run("[-]", init_mem, expected_mem);
  }

  {
    std::map<unsigned int, int> init_mem({{0, 10}});
    std::map<unsigned int, int> expected_mem({{0, 0}, {1, 10}});
    success = success && helpers::run("[->+<]", init_mem, expected_mem);
  }

  {
    std::map<unsigned int, int> init_mem({{0, 42}});
    std::map<unsigned int, int> expected_mem({{0, 0}, {2, 42}, {4, 42}});
    success = success && helpers::run("[>>+>>+<<<<-]", init_mem, expected_mem);
  }

  std::cout << "======= " << (success ? "PASS" : "FAIL") << " =======\n" << std::endl;

  return success;
}

bool Tests::run_all() {
  bool success = true;
  success = success && run_jump_right_tests();
  success = success && run_jump_left_tests();
  success = success && run_simple_programs_with_memory();

  std::cout << "======= " << (success ? "ALL PASS" : "FAIL") << " =======\n" << std::endl;

  return success;
}