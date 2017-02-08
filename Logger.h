/*
 * Logger.h
 *
 *  Created by bribin on Jan 28, 2017.
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <stdio.h>

#include "Arduino.h"

class Logger {

public:
    Logger(bool on);

    void debug(const char* format, ...);

private:
    bool _LOG_ON_ = false;

};

#endif /* LOGGER_H_ */
