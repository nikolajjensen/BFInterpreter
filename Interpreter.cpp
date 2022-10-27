#include "Interpreter.h"
#include <iostream>

Execution Interpreter::execute(const std::string& program) {
  std::map<unsigned int, int> memory;
  return execute(program, memory);
}

Execution Interpreter::execute(const std::string& program, std::map<unsigned int, int> &memory) {
  Execution execution(program, memory);

  create_bracket_table(execution);

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
int Interpreter::jump_right(const std::string& program, int program_ctr, int level) {
  char c = program[program_ctr];
  if(c == ']') {
    level--;
  } else if (c == '[') {
    level++;
  }

  program_ctr++;
  if(!((c == ']' && level == -1) || (program_ctr == program.length()))) {
    return jump_right(program, program_ctr, level);
  }

  return program_ctr;
}

/**
 * This method was inspired by a previous implementation of the 
 * BF interpreter made by 'Nikolaj Banke Jensen' for the PLD coursework in Scala. 
 * 
 * Many prominent changes have been mad; for details see Interpreter.h.
 */
int Interpreter::jump_left(const std::string& program, int program_ctr, int level) {
  char c = program[program_ctr];
  if(c == '[') {
    level--;
  } else if (c == ']') {
    level++;
  }

  if(c == '[' && level == -1) {
    program_ctr++;
  } else if(program_ctr == 0) {
    program_ctr = -1;
  } else {
    program_ctr--;
    return jump_left(program, program_ctr, level);
  }

  return program_ctr;
}


void Interpreter::create_bracket_table(Execution &execution) {
  execution.bracket_table.clear();
  
  for(std::size_t i = 0; i < execution.program.length(); ++i) {
    char c = execution.program[i];

    if(c == '[') {
      execution.bracket_table[i] = jump_right(execution.program, i + 1);
    } else if (c == ']') {
      execution.bracket_table[i] = jump_left(execution.program, i - 1);
    }
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
      execution.program_ctr = execution.bracket_table[execution.program_ctr];
    } else {
      execution.program_ctr++;
    }
    break;
  case ']':
    if(execution.getMemory(execution.memory_ptr) != 0) {
      execution.program_ctr = execution.bracket_table[execution.program_ctr];
    } else {
      execution.program_ctr++;
    }
    break;
  default:
    execution.program_ctr++;
    break;
  }
}