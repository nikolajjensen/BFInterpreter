#include <string>
#include <iostream>
#include "Utils.h"
#include "Interpreter.h"
#include "Test.h"

#define BF_EXTENSION ".bf"

/**
 * @brief Entrypoint of the application.
 * 
 * Pass argument '-t' at execution for running the test suite.
 * Pass a path to a BF file at execution for running the program within.
 * @return int 0 if no errors occurred, 1 otherwise.
 */
int main(int argc, char * argv[]) {
  if (argc < 2) {
    std::cout << "ERROR: You must provide either a path to a '" << BF_EXTENSION << "' file, or set the flag '-t' to run tests."  << std::endl;
    return 1;
  }

  std::string argument = argv[1];

  if(argument == "-t") {
    return Tests::run_all() ? 0 : 1;
  }
  
  if(!Utils::string_has_ending(argument, BF_EXTENSION)) {
    std::cout << "ERROR: the file at path '" << argument << "' does not end with '" << BF_EXTENSION << "'" << std::endl;
    return 1;
  }

  std::string program = Utils::load(argument);
  if(program == "") {
    std::cout << "ERROR: either the file at " << argument << " does not exist, or it is empty." << std::endl;
    return 1;
  }

  Interpreter::execute(program);
  return 0;
}