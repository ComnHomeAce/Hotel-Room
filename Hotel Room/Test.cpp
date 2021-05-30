#include <iostream>
#include "Hotel.h"
using namespace std;

int main()
{
	//Create HotelRoom object with parameters
	HotelRoom r1(104, 149.95);

	//Attempt setRate with invalid argument
	try
	{
		r1.setRate(-49.98);
	}
	catch (invalid_argument& ex)
	{
		cout << ex.what()<< endl;
	}

	//Print r1 information
	cout << r1.toString() << endl;
	
	cout << endl;

	//Create GuestRoom object with parameters
	GuestRoom g1(249, 234.96, 4, 3, 3);

	//Attempt setStatus with out of range value
	try
	{
		g1.setStatus(5);
	}
	catch (out_of_range& ex)
	{
		cout << ex.what() << endl;
	}

	//Print g1 information
	cout << g1.toString() << endl;

	cout << endl;

	//Create MeetingRoom object with parameters
	MeetingRoom m1(1001, 125, 1);

	//Print m1 information
	cout << m1.toString() << endl;
}