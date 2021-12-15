//file: Car.h
//Header file for Car class containing private and public fields and methods
//author: Ethan Kramer
 //LO1. Design and implement a class.  
	//LO1a. At least one class in a header file with non-trivial methods implemented in a cpp file


#ifndef VEHICLE_H
#define VEHICLE_H


#include <iostream>
class Vehicle
{
	//LO6. Use object-oriented encapsulation mechanisms such as interfaces and private members.
private:		// ENCAPSULATION: private and public fields/members
	//fields
	//------------------------------------------------------------------------------------
	std::string name;
	double price = 0;
	int num_doors = 0;
	bool leather_seats = true;
	int miles = 0;
	int accidents = 0;
	int num_seats = 0;
	

public:
	//setters
		//------------------------------------------------------------------------------------
	void set_name(std::string n) { name = n; }
	void set_price(double p) noexcept { price = p; }
	void set_num_doors(int d) noexcept { num_doors = d; }
	void set_leather_seats(bool s) noexcept { leather_seats = s; }
	void set_miles(int m) noexcept { miles = m; }
	void set_accidents(int a) noexcept { accidents = a; }
	void set_num_seats(int n) noexcept { num_seats = n; }

	//getters
	//------------------------------------------------------------------------------------
	std::string get_name() { return name; }
	double get_price() noexcept { return price; }
	double get_num_doors() noexcept { return num_doors; }
	bool get_leather_seats() noexcept { return leather_seats; }
	int get_miles() noexcept { return miles; }
	auto get_accidents() noexcept -> int { return accidents; }
	auto get_num_seats() noexcept -> int { return num_seats; }

	
	//----------------------------------------------------------------------------------------------------------------------------------------------------------

	//methods

	//----------------------------------------------------------------------------------------------------------------------------------------------------------


	/**
	 * @brief prints stats of car (the object type calling function determines which print_stats() is used)
	 
	 * LO3. Correctly reason about control flow in a program using dynamic dispatch. 
	*/
	virtual void print_stats() {
		std::cout << get_name() << std::endl;
		std::cout << "\t Price: $" << get_price() << std::endl;
		std::cout << "\t Miles: " << get_miles() << " miles" << std::endl;
		std::cout << "\t Accidents: " << get_accidents() << std::endl;
		std::cout << "\t Transmission Type: Automatic" << std::endl;
		std::cout << "\t Number of Seats: " << get_num_seats() << std::endl;
		std::cout << "\t Number of Doors: " << get_num_doors() << std::endl;
		std::cout << "\t Leather Seats:	Yes" << std::endl;
	}
};

#endif