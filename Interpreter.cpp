#include "Interpreter.h"
#include <iostream>

Execution Interpreter::execute(const std::string& program) {
  std::map<unsigned int, int> memory;
  return execute(program, memory);
}

Execution Interpreter::execute(const std::string& program, std::map<unsigned int, int> &memory) {
  Execution execution(program, memory);

  while(execution.program_ctr >= 0 && execution.program_ctr < program.length()) {
    progress(execution);
  }

  return execution;
}

/**
 * This method was inspired by a previous implementation of the 
 * BF interpreter made by 'Nikolaj Banke Jensen' for the PLD coursework in Scala. 
 * 
 * Many prominent changes have been mad; for details see Interpreter.h.
 */
void Interpreter::jump_right(Execution &execution, int level) {
  char c = execution.program[execution.program_ctr];
  if(c == ']') {
    level--;
  } else if (c == '[') {
    level++;
  }

  execution.program_ctr++;
  if(!((c == ']' && level == -1) || (execution.program_ctr == execution.program.length()))) {
    jump_right(execution, level);
  }
}

/**
 * This method was inspired by a previous implementation of the 
 * BF interpreter made by 'Nikolaj Banke Jensen' for the PLD coursework in Scala. 
 * 
 * Many prominent changes have been mad; for details see Interpreter.h.
 */
void Interpreter::jump_left(Execution &execution, int level) {
  char c = execution.program[execution.program_ctr];
  if(c == '[') {
    level--;
  } else if (c == ']') {
    level++;
  }

  if(c == '[' && level == -1) {
    execution.program_ctr++;
  } else if(execution.program_ctr == 0) {
    execution.program_ctr = -1;
  } else {
    execution.program_ctr--;
    jump_left(execution, level);
  }
}

/**
 * This method was inspired by a previous implementation of the 
 * BF interpreter made by 'Nikolaj Banke Jensen' for the PLD coursework in Scala. 
 * 
 * Many prominent changes have been mad; for details see Interpreter.h.
 */
void Interpreter::progress(Execution &execution) {
  char c = execution.program[execution.program_ctr];

  switch (c) {
  case '>':
    execution.program_ctr++;
    execution.memory_ptr++;
    break;
  case '<':
    execution.program_ctr++;
    execution.memory_ptr--;
    break;
  case '+':
    execution.program_ctr++;
    execution.setMemory(execution.memory_ptr, execution.getMemory(execution.memory_ptr) + 1);
    break;
  case '-':
    execution.program_ctr++;
    execution.setMemory(execution.memory_ptr, execution.getMemory(execution.memory_ptr) - 1);
    break;
  case '.':
    execution.program_ctr++;
    std::cout << static_cast<char>(execution.getMemory(execution.memory_ptr)) << std::flush;
    break;
  case '[':
    if(execution.getMemory(execution.memory_ptr) == 0) {
      execution.program_ctr++;
      jump_right(execution);
    } else {
      execution.program_ctr++;
    }
    break;
  case ']':
    if(execution.getMemory(execution.memory_ptr) != 0) {
      execution.program_ctr--;
      jump_left(execution);
    } else {
      execution.program_ctr++;
    }
    break;
  default:
    execution.program_ctr++;
    break;
  }
}