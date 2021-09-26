// Flight.h
// TODO: make Seat member seat an enum
#ifndef FLIGHT_H
#define FLIGHT_H
#include <string>
#include <vector>
using namespace std;
class Flight {
private:
  class Passenger {
  public:
    class Seat {
    public:
      int row;
      char seat;
      int getRow() const { return row; }
      char getSeat() const { return seat; }
      void setRow(const int row) { this->row = row; }
      void setSeat(const char seat) { this->seat = seat; }
    };
  public:
    string firstName, lastName, phone, id;
    Seat seat;
    Passenger();
    // passenger with 35 parameters lol
    Passenger(const string, const string, const string, const string, const int, const char);
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    string getPhone() const { return phone; }
    string getID() const { return id; }
    Seat getSeat() const { return seat; }
    void setFirstName(const string firstName) { this->firstName = firstName; }
    void setLastName(const string lastName) { this->lastName = lastName; }
    void setPhone(const string phone) { this->phone = phone; }
    void setID(const string id) { this->id = id; }
    void setSeat(const Seat seat) { this->seat = seat; }
  };

private:
  int rows, seats;
  string flightNumber;
  vector<Passenger> pass;

public:
  Flight();
  Flight(const int, const int, const string);
  int getRows() const { return rows; }
  int getSeats() const { return seats; }
  void setRows(const int rows) { this->rows = rows; }
  void setSeats(const int seats) { this->seats = seats; }
  void printSeatMap();
  void printPassengerInfo();
  bool isSeatOccupied(const int, const char);
  void addPassenger(const string firstName, const string lastName,
                    const string phone, const string id, const int row,
                    const char seat) {
    pass.emplace_back(firstName, lastName, phone, id, row, seat);
  }
  void addPassenger();
  bool removePassenger();
  void writePassengerFile();
};

#endif
