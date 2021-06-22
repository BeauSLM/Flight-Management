// main.h
// TODO: error handling for option select - incorrect number and other stuff

#include "Flight.h"

inline void cleanStandardInputStream() {
    int leftover;
    do {
        leftover = cin.get();
    } while(leftover != '\n' && leftover != EOF);
}

inline void pressEnter() {
    cout << "\n<<< Press Return to Continue>>>>" << endl;
    cin.get();
}

inline void titleScreen() {
    cout << "Version: 1.0" << endl;
    cout << "Flight Management Program in C++" << endl;
    cout << "Beau McCartney" << endl;
    pressEnter();
}

inline int optionSelect() {
    cout << "Please select one of the following options:" << endl;
    cout << "1. Display Flight Seat Map." << endl;
    cout << "2. Display Passenger's Information." << endl;
    cout << "3. Add a New Passenger." << endl;
    cout << "4. Remove an Existing Passenger." << endl;
    cout << "5. Save data." << endl;
    cout << "6. Quit." << endl;
    cout << "Enter your choice: (1, 2, 3, 4, 5 or 6) ";
    int number;
    cin >> number;
    cout << endl;
    return number;
}
