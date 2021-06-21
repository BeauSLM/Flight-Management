// main.h
// TODO: error handling for option select - incorrect number and other stuff
// TODO: maybe make a seperate function to print out the option menu?

#include "Flight.h"

inline void cleanStandardInputStream() {
    int leftover;
    do {
        leftover = std::cin.get();
    } while(leftover != '\n' && leftover != EOF);
}

inline void pressEnter() {
    std::cout << "\n<<< Press Return to Continue>>>>" << std::endl;
    std::cin.get();
}

inline void titleScreen() {
    std::cout << "Version: 1.0" << std::endl;
    std::cout << "Flight Management Program in C++" << std::endl;
    std::cout << "Beau McCartney" << std::endl;
    pressEnter();
}

inline int optionSelect() {
    std::cout << "Please select one of the following options:" << std::endl;
    std::cout << "1. Display Flight Seat Map." << std::endl;
    std::cout << "2. Display Passenger's Information." << std::endl;
    std::cout << "3. Add a New Passenger." << std::endl;
    std::cout << "4. Remove an Existing Passenger." << std::endl;
    std::cout << "5. Save data." << std::endl;
    std::cout << "6. Quit." << std::endl;
    std::cout << "Enter your choice: (1, 2, 3, 4, 5 or 6) " << std::endl;
    int number;
    std::cin >> number;
    return number;
}
