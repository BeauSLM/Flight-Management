// TODO: when adding passenger, check that length of passenger array doesn't exceed number of available seats and do something about it
// TODO: ensure passenger vector is always sorted by passenger id, implement binary search or something to find passengers by id
// TODO: handle case where names contain spaces
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

inline void cleanFileInputStream(ifstream &input);

class Flight {
    class Passenger {
        class Seat {
            private:
                int row;
                char seat;
            public:
                int getRow() const {
                    return this -> row;
                }

                int getSeat() const {
                    return this -> seat;
                }

                void setRow(const int row) {
                    this -> row = row;
                }

                void setSeat(const char seat) {
                    this -> seat = seat;
                }
        };
        private:
            string firstName, lastName, phone, id;
            Seat seat = Seat();
        public:
            Passenger();
            Passenger(const string firstName, const string lastName, const string phone, const string id, const int row, const char seat) {
                this -> firstName = firstName;
                this -> lastName = lastName;
                this -> phone = phone;
                this -> id = id;
                this -> seat.setRow(row);
                this -> seat.setSeat(seat);
            };

            string getFirstName() const {
                return this -> firstName;
            }

            string getLastName() const {
                return this ->lastName;
            }

            string getPhone() const {
                return this -> phone;
            }

            string getID() const {
                return this -> id;
            }

            Seat getSeat() const {
                return this -> seat;
            }

            void setFirstName(const string firstName) {
                this -> firstName = firstName;
            }

            void setLastName(const string lastName) {
                this -> lastName = lastName;
            }

            void setPhone(const string phone) {
                this -> phone = phone;
            }

            void setID(const string id) {
                this -> id = id;
            }

            void setSeat(const Seat seat) {
                this -> seat = seat;
            }
    };
    private:
        int rows;
        int seats;
        string flightNumber;
        vector<Passenger> passengers;
    public:
        // assumes that the file has enough seats to hold the given passengers
        Flight() {
            ifstream input;
            string fileName = "flight_info.txt";
            // cout << "Enter filename: ";
            // cin >> fileName;
            input.open("lib/" + fileName);
            // for(int i = 0; input.fail() && i < 2; i++) {
            //     cout << "Please enter a valid filename" << endl;
            //     cin >> fileName;
            //     input.clear();
            //     input.open("lib/" + fileName);
            // }

            // quick and dirty error handling
            if (input.fail()) {
                cout << "Can't open file - aborting" << endl;
                input.close();
                exit(1);
            } else {
                cout << "Opened file succesfully" << endl << endl;
            }

            // read in flight number, number of rows, and number of seats
            input >> flightNumber >> rows >> seats;
            while (!input.eof()) {
                string firstName, lastName, phone, id;
                int row;
                char seat;

                // read in the first few things from the file
                input >> firstName >> lastName >> phone;

                // iterate through all the spaces until the next character is the row number
                while (char(input.peek()) < '0' && char(input.peek()) != '\n') {
                    input.get();
                }

                // mini-algorithm to read in a decimal number one digit at a time - evil mwahaha
                row = input.get() - 48;
                while (char(input.peek()) <= '9') {
                    row = row * 10 + input.get() - 48;
                }

                // read in the seat and id
                input >> seat >> id;
                cleanFileInputStream(input);

                addPassenger(firstName, lastName, phone, id, row, seat);
            }
            input.close();
            cout << "Done reading from file" << endl << endl;
        }

        // used for testing
        Flight(const int rows, const int seats, const string flightNumber) {
            this -> rows = rows;
            this -> seats = seats;
            this -> flightNumber = flightNumber;
        }

        int getRows() const {
            return this -> rows;
        }

        int getSeats() const {
            return this -> seats;
        }

        void setRows(const int rows) {
            this -> rows = rows;
        }
        
        void setSeats(const int seats) {
            this -> seats = seats;
        }

        void printSeatMap() {
            ;
        }

        void printPassengerInfo() {
            cout << " ";
            for (int i = 0; i < 64; i++) {
                cout << "-";
            }
            for (size_t i = 0; i < passengers.size(); i++) {
                cout << passengers[i].getSeat().getRow() << endl;
            }
            cout << endl;
        }

        void addPassenger(const string firstName, const string lastName, const string phone, const string id, const int row, const char seat) {
            passengers.emplace_back(firstName, lastName, phone, id, row, seat); 
        }

        void addPassenger() {
            string firstName, lastName, phone, id;
            int row;
            char seat;

            cout << "Please enter the passenger id: " << endl;
            cin >> id;

            cout << "Please enter the passenger's first name: " << endl;
            cin >> firstName;

            cout << "Please enter the passenger's last name: " << endl;
            cin >> lastName;

            cout << "Please enter the passenger's phone number: " << endl;
            cin >> phone;
            
            cout << "\nEnter the passenger's desired row: " << endl;
            cin >> row;

            cout << "Enter the passenger's desired seat: " << endl;
            cin >> seat;

            passengers.emplace_back(firstName, lastName, phone, id, row, seat);
            cout << "Succesfully added a passenger!" << endl << endl;
        }

        bool removePassenger() {
            string id;
            cout << "Please enter the id of the passenger that needs to be removed: " << endl;
            cin >> id;
            
            for (size_t i = 0; i < passengers.size(); i++) {
                if (passengers[i].getID() == id) {
                    passengers.erase(passengers.begin() + i);
                    cout << "successfuly removed a passenger!" << endl << endl;
                    return true;
                }
            }
            cout << "couldn't remove the requested id" << endl << endl;
            return false;
        }
};

inline void cleanFileInputStream(ifstream& input) {
    int leftover;
    do {
        leftover = input.get();
        input.peek();
    } while( leftover != '\n' && leftover != EOF);
}
