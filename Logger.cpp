/*
 * Logger.cpp
 *
 *  Created by bribin on Jan 28, 2017.
 */
#include "Logger.h"

Logger::Logger(bool on) {
    _LOG_ON_ = on;
}

void Logger::debug(const char message[]) {
//    Serial.println(_LOG_ON_);
    if (_LOG_ON_) {                 //FIXME why always true ??
        Serial.println(message);
    }
}

void Logger::debug(int num) {
//    Serial.println(_LOG_ON_);
    if (_LOG_ON_) {
        Serial.println(num);
    }
}
