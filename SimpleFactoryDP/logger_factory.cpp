#include "logger_factory.hpp"


ILogger* LoggerFactory::createLogger(LogLevel plogLevel){
    if(pLogLevel == LogLevel::DEBUG){
        return new debugLogger();
    }
    if(pLogLevel == LogLevel::INFO){
        return new InfoLogger();
    }
    if(pLogLevel == LogLevel::ERROR){
        return new ErrorLogger();
    }
    return nullptr;
}