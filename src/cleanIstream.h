#ifndef CLEANISTREAM_H
#define CLEANISTREAM_H
#include <iostream>
#include <fstream>
#include "Flight.h"
using namespace std;

inline void cleanFileInputStream(ifstream &input) {
  int leftover;
  do {
    leftover = input.get();
    input.peek();
  } while (leftover != '\n' && leftover != EOF);
}

inline void cleanStandardInputStream() {
    int leftover;
    do {
        leftover = cin.get();
    } while(leftover != '\n' && leftover != EOF);
}

#endif
