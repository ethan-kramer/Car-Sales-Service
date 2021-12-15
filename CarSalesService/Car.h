//file: Car.h
//Header file for Car class containing private and public fields and methods
//author: Ethan Kramer



#ifndef CAR_H
#define CAR_H


#include <string>
#include "Vehicle.h"

class Car :
	public Vehicle																						//LO2a. Include comments describing the visibility inheritance model
{
private:	// ENCAPSULATION: private (fields)
	//fields
	//------------------------------------------------------------------------------------
	double trunk_size = 0;
public:		// ENCAPSULATION: public (methods and constructors)
	//setters
	//------------------------------------------------------------------------------------
	void set_trunk_size(double size) noexcept{ trunk_size = size; }

	//getters
	//------------------------------------------------------------------------------------
	auto get_trunk_size() noexcept -> double { return trunk_size; }


	//constructors
	Car() = default;	// default constructor


	//LO1b.Overload a constructor
	//LO1c. Utilize an initialization list
	Car(std::string n, double p, int m, int a, int s, int d, double ts) {
		set_name(n);
		set_price(p);
		set_miles(m);
		set_accidents(a);
		set_num_seats(s);
		set_num_doors(d);
		set_trunk_size(ts);	
	}		//overloaded constructor setting fields
	//----------------------------------------------------------------------------------------------------------------------------------------------------------

	//methods
	
	//----------------------------------------------------------------------------------------------------------------------------------------------------------


	/**
	 * @brief prints stats of car (the object type calling function determines which print_stats() is used)
	 * 
	 * LO3. Correctly reason about control flow in a program using dynamic dispatch. 
	*/
	void print_stats() override {					//In a member function declaration or definition, override specifier ensures that the function is virtual 
		std::cout << get_name() << std::endl;		//and is overriding a virtual function from a base class
		std::cout << "\t Price: $" << get_price() << std::endl;
		std::cout << "\t Miles: " << get_miles() << " miles" << std::endl;
		std::cout << "\t Accidents: " << get_accidents() << std::endl;
		std::cout << "\t Transmission Type: Automatic" << std::endl;
		std::cout << "\t Number of Seats: " << get_num_seats() << std::endl;
		std::cout << "\t Number of Doors: " << get_num_doors() << std::endl;
		std::cout << "\t Leather Seats:	Yes" << std::endl;
		std::cout << "\t Trunk Size: " << get_trunk_size() << " Cubic Feet" << std::endl;
	}
};

#endif