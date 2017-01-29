#include "led_matrix.h"

const int R1 = 2;
const int R2 = 3;
const int R3 = 7;

const int C1 = 5;
const int C2 = 4;
const int C3 = 6;

const int MATRIX_SIZE = 3;
const int ROWS[] = { R1, R2, R3 };
const int COLS[] = { C1, C2, C3 };

const int MATRIX[9][2] = { { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 0 }, { 1, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 }, { 2, 2 } };

const int CIRCLE_SIZE = 6;
const int CIRCLES[CIRCLE_SIZE][15] = { { 8, 0, 1, 2, 5, 8, 7, 6, 3 }, { 9, 0, 1, 2, 3, 4, 5, 6, 7, 8 }, { 12, 0, 1, 2,
        5, 4, 3, 6, 7, 8, 5, 4, 3 }, { 12, 0, 1, 4, 7, 8, 5, 2, 1, 4, 7, 6, 3 }, { 12, 0, 3, 4, 5, 8, 7, 6, 3, 4, 5, 2,
        1 }, { 8, 0, 4, 8, 5, 2, 4, 6, 3 } };

Logger logger(false);

void clear() {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        digitalWrite(ROWS[i], LOW);
    }
    for (int i = 0; i < MATRIX_SIZE; i++) {
        digitalWrite(COLS[i], LOW);
    }
}

void allLightsOn() {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        digitalWrite(ROWS[i], HIGH);
    }
    for (int i = 0; i < MATRIX_SIZE; i++) {
        digitalWrite(COLS[i], LOW);
    }
}

void setup() {
    Serial.begin(9600);

    pinMode(R1, OUTPUT);
    pinMode(R2, OUTPUT);
    pinMode(R3, OUTPUT);

    pinMode(C1, OUTPUT);
    pinMode(C2, OUTPUT);
    pinMode(C3, OUTPUT);

    clear();
}

void lightMatrix(int pos) {
    int row = MATRIX[pos][0];
    int col = MATRIX[pos][1];
    logger.debug(row);
    logger.debug(col);

    for (int i = 0; i < MATRIX_SIZE; i++) {
        if (i == row) {
            digitalWrite(ROWS[i], HIGH);
        } else {
            digitalWrite(ROWS[i], LOW);
        }
    }
    for (int i = 0; i < MATRIX_SIZE; i++) {
        if (i == col) {
            digitalWrite(COLS[i], LOW);
        } else {
            digitalWrite(COLS[i], HIGH);
        }
    }
}

void lightCircle(int cindex, int sleep) {
    int* circle = CIRCLES[cindex];

    int length = *circle;
    circle += 1;
    logger.debug(length);

    for (int i = 0; i < length; i++, circle++) {
        int mindex = *circle;
        logger.debug("--");
        logger.debug(mindex);

        int* pos = MATRIX[mindex];
        logger.debug(*pos);
        logger.debug(*(pos + 1));

        lightMatrix(mindex);
        delay(sleep);
    }
}

void lightCircle(int cindex) {
    int sleep = 300;
    for (int i = 0; i < 3; i++, sleep -= 100) {
        lightCircle(cindex, sleep);
    }
}

void loop() {
    logger.debug("----------------------");

    int sleep = 300;

    for (int i = 0; i < 3; i++) {
        allLightsOn();
        delay(sleep);
        clear();
        delay(sleep);
    }

    lightCircle(0);
    lightCircle(1);
    lightCircle(2);
    lightCircle(3);
    lightCircle(4);

}
