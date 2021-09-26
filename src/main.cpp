// main.cpp
// Beau McCartney
#include "Flight.h"
#include "cleanIstream.h"

using namespace std;

void pressEnter();
void titleScreen();
void titleScreen();
int optionSelect();

int main(int argc, const char** argv) {
    titleScreen();
    Flight f;
    int choice;

    while ((choice = optionSelect())) {
        switch (choice) {
            // seat map
            case 1:
                f.printSeatMap();
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
                f.writePassengerFile();
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

 void pressEnter() {
    cout << "\n<<< Press Return to Continue>>>>" << endl;
    cin.get();
}

 void titleScreen() {
    cout << "Version: 1.0" << endl;
    cout << "Flight Management Program in C++" << endl;
    cout << "Beau McCartney" << endl;
    pressEnter();
}

 int optionSelect() {
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
