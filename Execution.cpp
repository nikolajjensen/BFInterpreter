#include "Execution.h"


Execution::Execution(const std::string& program_in) : program(program_in), program_ctr(0), memory_ptr(0), memory(), bracket_table() {}
Execution::Execution(const std::string& program_in, std::map<unsigned int, int>& memory_in) : program(program_in), program_ctr(0), memory_ptr(0), memory(memory_in), bracket_table() {}

int Execution::getMemory(unsigned int& key) {
  if(memory.find(key) != memory.end()) {
    return memory[key];
  } else {
    return 0;
  }
}

void Execution::setMemory(unsigned int& key, int value) {
  memory[key] = value;
}