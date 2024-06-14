#include "logger_factory.hpp"


int main(){
    ILogger* debugLogger = LoggerFactory::createLogger(LogLevel::DEBUG);
    ILogger* infoLogger = LoggerFactory::createLogger(LogLevel::INFO);
    ILogger* errorLogger = LoggerFactory::createLogger(LogLevel::ERROR);     

    //here we only depend on interface not on debugLogger or any other logger,
    //We can add another type of logger and we have not to worry about that
    //during run time what we need logger factory will give to uss.
    //LoggerFactory is of type static and it it is returning only interface.

    debugLogger->log("This is a debug log message");
    infoLogger->log("This is a info log message");
    errorLogger->log("This is a error log message");

    delete debugLogger;
    delete infoLogger;
    delete errorLogger;

    return 0;
}