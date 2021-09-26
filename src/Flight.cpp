// TODO: when adding passenger, check that length of passenger array doesn't
// exceed number of available seats and do something about it
// TODO: make sure you can't add two passengers to the same seat
// TODO: ensure passenger vector is always sorted by passenger id, implement
// binary search or something to find passengers by id
// TODO: handle case where names contain spaces
// TODO: write destructor that automatically populates the output file with the
// passenger array
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include "Flight.h"
#include "cleanIstream.h"
using namespace std;

// assumes that the file has enough seats to hold the given passengers
Flight::Flight() {
  ifstream input;
  string fileName = "flight_info.txt";
  input.open("lib/" + fileName);

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

    // mini-algorithm to read in a decimal number one digit at a time - evil
    // mwahaha
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
Flight::Flight(const int rows, const int seats, const string flightNumber) {
  this->rows = rows;
  this->seats = seats;
  this->flightNumber = flightNumber;
}


void Flight::printSeatMap() {
  cout << "     ";
  for (char i = 'A'; i < char('A' + seats); i++) {
    // print row letters on top
    printf("%-4c", i);
  }
  cout << endl << "   ";

  for (size_t i = 0; i < size_t(seats); i++) {
    cout << "+---";
  }
  cout << "+" << endl;

  for (size_t row = 0; row < size_t(rows) * 2; row++) {
    if (row % 2) {
      cout << "   ";
      for (size_t column = 0; column < size_t(seats); column++) {
        cout << "+---";
      }
      cout << "+";
    } else {
      printf("%-3li|", row / 2);
      for (char column = 'A'; column < char('A' + seats); column++) {
        if (isSeatOccupied(row / 2, column)) {
          cout << " X |";
        } else {
          cout << "   |";
        }
      }
    }

    cout << endl;
  }

  cout << endl;
}

void Flight::printPassengerInfo() {
  printf("%-17s%-17s%-15s%-6s%-6s%-5s\n", "First Name", "Last Name", "Phone",
         "Row", "Seat", "ID");
  cout << " ";
  for (int i = 0; i < 65; i++) {
    cout << "-";
  }
  cout << endl;
  for (size_t i = 0; i < pass.size(); i++) {
    printf("%-17s%-16s%-16s%-6d%-6c%-5s\n", pass[i].getFirstName().c_str(),
           pass[i].getLastName().c_str(), pass[i].getPhone().c_str(),
           pass[i].getSeat().getRow(), pass[i].getSeat().getSeat(),
           pass[i].getID().c_str());
    cout << " ";
    for (int i = 0; i < 65; i++) {
      cout << "-";
    }
    cout << endl;
  }
  cout << endl;
}

bool Flight::isSeatOccupied(const int row, const char seat) {
  for (size_t i = 0; i < pass.size(); i++) {
    // quick note, if there is a large number of rows and a relatively small
    // number of seats, checking the seat first is significantly faster as you
    // rule out more row-seat pairs per check when you check the seat first
    if (pass[i].getSeat().getSeat() == seat &&
        pass[i].getSeat().getRow() == row) {
      return true;
    }
  }
  return false;
}

void Flight::addPassenger() {
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

  pass.emplace_back(firstName, lastName, phone, id, row, seat);
  cout << "Succesfully added a passenger!" << endl << endl;
}

bool Flight::removePassenger() {
  string id;
  cout << "Please enter the id of the passenger that needs to be removed: "
       << endl;
  cin >> id;

  for (size_t i = 0; i < pass.size(); i++) {
    if (pass[i].getID() == id) {
      pass.erase(pass.begin() + i);
      // TODO: better message here
      cout << "successfuly removed a passenger!" << endl << endl;
      return true;
    }
  }
  // TODO: better message here
  cout << "couldn't remove the requested id" << endl << endl;
  return false;
}

// so my initial plan was fprintf for formatted text...
void Flight::writePassengerFile() {
  FILE *output;
  output = fopen("lib/flight_info.txt", "w");
  if (output == NULL) {
    cout << "man idk just complain lul" << endl;
    return;
  }

  if (!fprintf(output, "%-9s%-6d%d\n", flightNumber.c_str(), rows, seats)) {
    cout << "Couldn't write flight info" << endl;
  }
  for (size_t i = 0; i < pass.size(); i++) {
    if (!fprintf(output, "%-20s%-20s%-20s%-4s%s\n",
                 pass[i].getFirstName().c_str(), pass[i].getLastName().c_str(),
                 pass[i].getPhone().c_str(),
                 (to_string(pass[i].getSeat().getRow()) +
                  pass[i].getSeat().getSeat())
                     .c_str(),
                 pass[i].getID().c_str())) {
      cout << "There was a problem writing passenger info" << endl;
    }
  }
  fclose(output);
}

Flight::Passenger::Passenger(const string firstName, const string lastName, 
        const string phone, const string id, int row, char seat) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->phone = phone;
    this->id = id;
    this->seat.row = row;
    this->seat.seat = seat;
}
