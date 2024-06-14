#pragma once
#include "ilogger.hpp"
#include "debug_logger.hpp"
#include "info_logger.hpp"
#include "error_logger.hpp"


class LoggerFactory{
    public: 
    static ILogger* createLogger(LogLevel plogLevel);  
    //returning a interface and if add another logger then nothing is going to change.
};



// The .hpp file extension is commonly used in C++ programming to denote a C++ header file. Header files in C++ typically contain declarations for functions, classes, and variables, which can then be included in multiple source files (.cpp files). Here are some key points about .hpp files:

// Purpose: The .hpp file extension is used to differentiate C++ header files from C header files, which usually use the .h extension. This differentiation helps in organizing code and making it clear that the header is intended for C++.

// Contents:

// Declarations of functions, classes, and variables.
// Include guards or #pragma once to prevent multiple inclusions.
// Template definitions (since templates need to be defined in headers due to their nature).
// Usage:

// Included in C++ source files (.cpp files) using the #include directive.
// Helps in separating interface (declaration) from implementation, promoting modularity and reusability.
