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
    if (_LOG_ON_) {
        Serial.println(message);
    }
}

void Logger::debug(int num) {
    if (_LOG_ON_) {
        Serial.println(num);
    }
}
