#ifndef HOTEL_H
#define HOTEL_H
#include <string>
using namespace std;

//Define class HotelRoom
class HotelRoom
{
private:
	//Attributes
	int roomNumber; //Room number
	double dailyRate; //Room rate

public:
	//Constructors
	HotelRoom(); //Default constructor
	HotelRoom(int number, double rate); //Constructor with parameters

	//Functions
	int getRoom() const; //Gets roomNumber
	double getRate() const; //Gets dailyRate

	void setRoom(int number); //Sets roomNumber
	void setRate(double rate); //Sets dailyRate

	string toString() const; //Sends private data fields to stringstream
};

//Derive class GuestRoom from HotelRoom
class GuestRoom : public HotelRoom
{
private:
	//Attributes
	int capacity; //Max number of guests in room
	int status; //Number of guests in room
	int day; //Number of days guests will occupy room

public:
	//Constructors
	GuestRoom(); //Default constructor
	GuestRoom(int roomNumber, double rate, int maxGuests, int guestCount, int stayLength); //Constructor with parameters

	//Functions
	int getCapacity(); //Gets capacity
	int getStatus(); //Gets status
	int getDay(); //Gets day

	void setCapacity(int maxGuests); //Sets capacity
	void setStatus(int guestCount); //Sets status
	void setDay(int stayLength); //Sets day

	double calculateBill() const; //Returns bill amount

	string toString() const; //Sends private data fields and bill amount to stringstream

};

//Derive class MeetingRoom from HotelRoom
class MeetingRoom : public HotelRoom
{
private:
	//Attributes
	int seats; //Number of seats in room
	int status; //Booked(1) or not booked(0)

public:
	//Constructors
	MeetingRoom(); //Default constructor
	MeetingRoom(int roomNumber, int seatCount, int bookingStatus); //Constructor with parameters

	//Functions
	int getSeats(); //Gets seats
	int getStatus(); //Gets status

	void setSeats(int seatCount); //Sets seats
	void setStatus(int bookingStatus); //Sets status

	double calculateBill() const; //Returns bill amount

	string toString() const; //Sends private data fields and bill amount to stringstream
};
#endif