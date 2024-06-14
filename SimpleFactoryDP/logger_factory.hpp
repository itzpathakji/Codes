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