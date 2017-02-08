/*
 * Logger.cpp
 *
 *  Created by bribin on Jan 28, 2017.
 */
#include "Logger.h"

Logger::Logger(bool on) {
    _LOG_ON_ = on;
}

void Logger::debug(const char* format, ...) {
    if (!_LOG_ON_) {
        return;
    }

    va_list argp;
    va_start(argp, format);

    char buf[512];
    vsprintf(buf, format, argp);

    va_end(argp);

    Serial.println(buf);
}
