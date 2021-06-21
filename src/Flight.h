// TODO: when adding passenger, check that length of passenger array doesn't exceed number of available seats and do something about it
#include <iostream>
#include <string>
#include <vector>
using namespace std;

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
        vector<Passenger> passengers;
    public:
        Flight();
        Flight(const int rows, const int seats) {
            this -> rows = rows;
            this -> seats = seats;
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
            for (size_t i = 0; i < passengers.size(); i++) {
                cout << passengers[i].getFirstName() << endl;
            }
            cout << endl;
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
