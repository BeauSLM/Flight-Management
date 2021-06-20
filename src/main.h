// main.h

#include <fstream>
#include <iostream>

void pressEnter() {
    std::cout << "\n<<< Press Return to Continue>>>>" << std::endl;
    std::cin.get();
}

void cleanStandardInputStream() {
    int leftover;
    do {
        leftover = std::cin.get();
    } while(leftover != '\n' && leftover != EOF);
}

void openFlightInfoFile() {
    std::ifstream input;
    input.open("../lib/flight_info.txt");
    input.close();
}
