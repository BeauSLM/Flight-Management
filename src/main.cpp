// main.cpp
// Beau McCartney
#include "main.h"

int main(int argc, const char** argv) {
    titleScreen();
    Flight f = Flight();
    int choice;

    while ((choice = optionSelect())) {
        switch (choice) {
            // seat map
            case 1:
                break;
            // passenger info
            case 2:
                f.printPassengerInfo();
                break;
            // add new passenger
            case 3:
                f.addPassenger();
                break;
            // remove passenger
            case 4:
                f.removePassenger();
                break;
            // save flight info (i.e. write)
            case 5:
                break;
            // Quit
            case 6:
                exit(0);
                break;
        }
    }

    if (!choice) {
        std::cout << "Please enter a number between 1 and 6" << std::endl;
        exit(1);
    }

    return 0;
}
