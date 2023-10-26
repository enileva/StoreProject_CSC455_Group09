#include "CompileAndRun.h"
#include <cstdlib>
#include <iostream>

void compileAndRun(std::string command) {
    if (system(command.c_str()) != 0) {
        std::cout << "Error: Compilation or execution failed.\n";
        exit(EXIT_FAILURE);
    }
}