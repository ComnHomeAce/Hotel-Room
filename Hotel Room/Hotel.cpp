#include <iostream>
#include <exception>
#include <stdexcept>
#include <sstream>
#include <string>
#include "Hotel.h"
using namespace std;

//======================================== Hotel Room ========================================
//Constructors
HotelRoom::HotelRoom() //Default constructor
{
	roomNumber = 0;
	dailyRate = 0.00;
}
HotelRoom::HotelRoom(int number, double rate) //Constructor with parameters
{
	if (number < 0 || rate < 0) //Checks for negative value
		throw invalid_argument("Negative Parameter");
	
	roomNumber = number;
	dailyRate = rate;
}

//Functions
int HotelRoom::getRoom() const //Gets roomNumber
{
	return roomNumber;
}
double HotelRoom::getRate() const //Gets dailyRate
{
	return dailyRate;
}
void HotelRoom::setRoom(int number) //Sets roomNumber
{
	if (number < 0) //Checks for negative value
		throw invalid_argument("Negative Parameter");
	
	roomNumber = number;
}
void HotelRoom::setRate(double rate) //Sets dailyRate
{
	if (rate < 0) //Checks for negative value
		throw invalid_argument("Negative Parameter");
	
	dailyRate = rate;
}
string HotelRoom::toString() const //Sends private data fields to stringstream
{
	stringstream ss;
	ss << "Room Number: " << roomNumber << ", Daily Rate: $" << dailyRate;
	return ss.str();
}

//======================================== Guest Room ========================================
//Constructors
GuestRoom::GuestRoom() //Default constructor
{
	setRoom(0);
	setRate(0.00);
	capacity = 0;
	status = 0;
	day = 0;
}
GuestRoom::GuestRoom(int roomNumber, double rate, int maxGuests, int guestCount, int stayLength) //Constructor with parameters
{
	if (guestCount > maxGuests) //Checks guest count against room capacity
		throw out_of_range("Guest Count Exceeds Room Capacity");

	setRoom(roomNumber);
	setRate(rate);
	capacity = maxGuests;
	status = guestCount;
	day = stayLength;
}

//Functions
int GuestRoom::getCapacity() //Gets capacity
{
	return capacity;
}
int GuestRoom::getStatus() //Gets status
{
	return status;
}
int GuestRoom::getDay() //Gets day
{
	return day;
}
void GuestRoom::setCapacity(int maxGuests) //Sets capacity
{
	capacity = maxGuests;
}
void GuestRoom::setStatus(int guestCount) //Sets status
{
	if (guestCount > capacity) //Checks guest count against room capacity
		throw out_of_range("Guest Count Exceeds Room Capacity");
	status = guestCount;
}
void GuestRoom::setDay(int stayLength) //Sets day
{
	day = stayLength;
}
double GuestRoom::calculateBill() const //Returns bill amount
{
	return day * getRate();
}
string GuestRoom::toString() const //Sends private data fields and bill amount to stringstream
{
	stringstream ss;
	ss << "Room Number: " << getRoom() << ", Daily Rate: $" << getRate()
		<< ", Room Capacity: " << capacity << ", Number of Occupants: " << status << ", Total Bill: $" << calculateBill();
	return ss.str();
}

//======================================== Meeting Room ========================================
//Constructors
MeetingRoom::MeetingRoom() //Default constructor
{
	setRoom(0);
	seats = 0;
	status = 0;
}
MeetingRoom::MeetingRoom(int roomNumber, int seatCount, int bookingStatus) //Constructor with parameters
{
	setRoom(roomNumber);
	seats = seatCount;
	status = bookingStatus;
}
//Functions
int MeetingRoom::getSeats() //Gets seats
{
	return seats;
}
int MeetingRoom::getStatus() //Gets status
{
	return status;
}
void MeetingRoom::setSeats(int seatCount) //Sets seats
{
	seats = seatCount;
}
void MeetingRoom::setStatus(int bookingStatus) //Sets status
{
	status = bookingStatus;
}
double MeetingRoom::calculateBill() const //Returns bill amount
{
	return seats * 10.00 + 500.00;
}
string MeetingRoom::toString() const //Sends private data fields and bill amount to stringstream
{
	stringstream ss;
	ss << "Room Number: " << getRoom() << ", Room Capacity: " << seats << ", Booking Status: " << status << ", Total Bill: $" << calculateBill();
	return ss.str();
}