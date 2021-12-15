/**
 * @file CarSalesService.cpp
 * @brief Main implementation file for the program
 * 
 * Contains main function, list of car objects, and functions necessary for the program to run smoothly
 * 
 * @author Ethan Kramer
 * @bug No known bugs.
*/
 

//																Notes
//--------------------------------------------------------------------------------------------------------------------------------
//LO4. Include a comment in which you compare and contrast the procedural/functional approach and the object-oriented approach
//Because I am using object oriented programming instead of procedural, a lot of fields are encapsulated in header files,
// and are accessed in the main file by creating objects (instances of the class) and using the dot operator.
//
//LO5. Explain the relationship between object-oriented inheritance (code-sharing and overriding) and subtyping (the idea of a subtype being usable in a context that expects the supertype).
//The relationship between inheritance and subtyping is that subtyping is a form of inheritance.  For example, in this program, subtyping is used in the 
//	in_stock vector to list objects of type car and truck when it's expecting objects of type vehicle because car and truck both inherit from vehicle
//
//
//The noexcept specifier defines a function as non-throwing. (clang tidy)
//To define a function as non-throwing, we can use the noexcept specifier in the function declaration,
// placed to the RIGHT of the function parameter list (but before {})
//--------------------------------------------------------------------------------------------------------------------------------


#include <iostream>
#include "CarSalesService.h"
#include "Car.h"
#include "Truck.h"
#include "Vehicle.h"
#include <vector>


//prototypes
void over_the_top_greeting();
void print_menu();
void print_stock(std::vector<Vehicle> stock);
void browse_cars(std::vector<Vehicle> stock);		//LO7. Define and use iterators and other operations on aggregates, INCLUDING OPERATIONS THAT TAKE FUNCTIONS AS ARGUMENTS.
void finance_car(double p);							//takes in car.get(price)   (function taking other function as argument 
void take_payment();


/**
 * @brief main function for the program
 * @return int (0)
*/
auto main() -> int		//trailing return type (clangtidy)
{
	try {		//clang tidy 
		// Cars in Stock objects
		Car mazda3(MAZDA3_NAME, MAZDA3_PRICE, MAZDA3_MILES, MAZDA3_ACCIDENTS, MAZDA3_NUM_SEATS, MAZDA3_NUM_DOORS, MAZDA3_TRUNK_SIZE);
		Truck chevy_colorado(CHEVY_COLORADO_NAME, CHEVY_COLORADO_PRICE, CHEVY_COLORADO_MILES, CHEVY_COLORADO_ACCIDENTS, CHEVY_COLORADO_NUM_SEATS, CHEVY_COLORADO_NUM_DOORS, CHEVY_COLORADO_BED_SIZE, CHEVY_COLORADO_TOWING_CAPACITY);
		Car toyota_camry(TOYOTA_CAMRY_NAME, TOYOTA_CAMRY_PRICE, TOYOTA_CAMRY_MILES, TOYOTA_CAMRY_ACCIDENTS, TOYOTA_CAMRY_NUM_SEATS, TOYOTA_CAMRY_NUM_DOORS, TOYOTA_CAMRY_TRUNK_SIZE);
		Car honda_civic(HONDA_CIVIC_NAME, HONDA_CIVIC_PRICE, HONDA_CIVIC_MILES, HONDA_CIVIC_ACCIDENTS, HONDA_CIVIC_NUM_SEATS, HONDA_CIVIC_NUM_DOORS, HONDA_CIVIC_TRUNK_SIZE);
		Car hyundai_elantra(HYUNDAI_ELANTRA_NAME, HYUNDAI_ELANTRA_PRICE, HYUNDAI_ELANTRA_MILES, HYUNDAI_ELANTRA_ACCIDENTS, HYUNDAI_ELANTRA_NUM_SEATS, HYUNDAI_ELANTRA_NUM_DOORS, HYUNDAI_ELANTRA_TRUNK_SIZE);

		// list of cars in stock (vector for passing as argument)
		std::vector<Vehicle> in_stock = { mazda3, chevy_colorado, toyota_camry, honda_civic, hyundai_elantra };		// type vehicle so it can take cars and trucks (polymorphism)


		over_the_top_greeting();
		std::cout << "Welcome to Kramer Car Sales! We are currently offering a downpayment of $0 for the purchase of any car as long as it is paid off in one year!\n" << std::endl;
		int flag = RUNNING;
		while (flag != 0) {		// main menu loop
			print_menu();
			int menu_choice = FLAG;
			std::cout << "Type the number corresponding to the feature you'd like to use: ";
			std::cin >> menu_choice;

			//switch for feature selection
			switch (menu_choice) {
			// Browse cars in stock
			case BROWSE:
				browse_cars(in_stock);			
				break;

			//purchase car
			case PURCHASE:
			{
				print_stock(in_stock);
				int car_for_sale = 0;
				std::cout << "Enter the number corresponding to the car you'd like to purchase: ";
				std::cin >> car_for_sale;
				switch (car_for_sale) {
				case MAZDA3:
					std::cout << "\nProceeding to checkout..." << std::endl;
					mazda3.print_stats();
					finance_car(mazda3.get_price());		// function taking a function as an argument
					take_payment();
					std::cout << "Thank you for your purchase!  Your new vehicle will be ready for pickup in 3 business days.\nYou have been sent a confirmation email." << std::endl;
					break;
				case CHEVRY_COLORADO:
					std::cout << "\nProceeding to checkout..." << std::endl;
					chevy_colorado.print_stats();
					finance_car(chevy_colorado.get_price());
					take_payment();
					std::cout << "Thank you for your purchase!  Your new vehicle will be ready for pickup in 3 business days.\nYou have been sent a confirmation email." << std::endl;
					break;
				case TOYOTA_CAMRY:
					std::cout << "\nProceeding to checkout..." << std::endl;
					toyota_camry.print_stats();
					finance_car(toyota_camry.get_price());
					take_payment();
					std::cout << "Thank you for your purchase!  Your new vehicle will be ready for pickup in 3 business days.\nYou have been sent a confirmation email." << std::endl;
					break;
				case HONDA_CIVIC:
					std::cout << "\nProceeding to checkout..." << std::endl;
					honda_civic.print_stats();
					finance_car(honda_civic.get_price());
					take_payment();
					std::cout << "Thank you for your purchase!  Your new vehicle will be ready for pickup in 3 business days.\nYou have been sent a confirmation email." << std::endl;
					break;
				case HYUNDAI_ELANTRA:
					std::cout << "\nProceeding to checkout..." << std::endl;
					hyundai_elantra.print_stats();
					finance_car(hyundai_elantra.get_price());
					take_payment();
					std::cout << "Thank you for your purchase!  Your new vehicle will be ready for pickup in 3 business days.\nYou have been sent a confirmation email." << std::endl;
					break;
				default:
					std::cout << "Your input must be a number between 1 and 5." << std::endl;
				}	// end purchase switch statement

				break; // end purchase car (inside switch 2)
			}			 // end case 2

			case 3:
				std::cout << "\nType 0 to quit, or any other number to go back to the main menu: ";
				std::cin >> flag;
				std::cout << std::endl;
				break;
			default:
				std::cout << "Invalid input." << std::endl;
				
			}	// end feature selection
			std::cout << "\nType 0 to quit, or any other number to go back to the main menu: ";
			std::cin >> flag;
			std::cout << std::endl;
		}	// end main menu loop
		std::cout << "\n\nThank you for shopping, have a great day!" << std::endl;	
	}// end try
	catch (...) {
		std::cout << "Your input caused an unexpected issue.  Please try again." << std::endl;		// clang tidy
	}
}	// end main


/**
 * @brief function printing welcome message
*/
void over_the_top_greeting() {
	std::cout << ("\t\t\t\t\t\t~~~~~~~~~~~~~~~~~") << std::endl;
	std::cout << ("\t\t\t\t\t\t*               *") << std::endl;
	std::cout << ("\t\t\t\t\t\t* ~~~Welcome~~~ *") << std::endl;
	std::cout << ("\t\t\t\t\t\t*               *") << std::endl;
	std::cout << ("\t\t\t\t\t\t~~~~~~~~~~~~~~~~~\n") << std::endl;

}


/**
 * @brief function printing menu options
*/
void print_menu() {
	std::cout << "\n\t\t\t\t\t       ~~~~~ Main Menu~~~~~" << std::endl;
	std::cout << "\t 1. Browse Cars in Stock" << std::endl;
	std::cout << "\t 2. Buy Car" << std::endl;
	std::cout << "\t 3. Exit\n" << std::endl;
}


/**
 * @brief function allowing user to browse cars in stock
 * @param stock (array of type Vehicle)
*/
void browse_cars(std::vector<Vehicle>stock) {
	bool browsing = true;
	while (browsing) {
		print_stock(stock);
		std::cout << "To view details on a specific car, enter the number corresponding to that car here (0 to go back to menu): " << std::endl;
		int car_choice = FLAG;
		std::cin >> car_choice;
		switch (car_choice) {
		case MAZDA3:
			stock.at(0).print_stats();
			break;
		case CHEVRY_COLORADO:
			stock.at(1).print_stats();
			break;
		case TOYOTA_CAMRY:
			stock.at(2).print_stats();
			break;
		case HONDA_CIVIC:
			stock.at(3).print_stats();
			break;
		case HYUNDAI_ELANTRA:
			stock.at(4).print_stats();
			break;
		default:
			std::cout << "Exiting car browser..." << std::endl;
		}	// end switch statement
		int again = 0;
		std::cout << "To stop browsing enter 5, to continue to look at other cars enter any other number: ";
		std::cin >> again;
		if (again == STOP_BROWSING) { browsing = false; }
	}	// end browsing loop
}// end browse_cars()


/**
 * @brief prints names of all vehicles in stock numbered	
 * @param stock (array of type Vehicle
*/
void print_stock(std::vector<Vehicle>stock) {				
																//LO7. Define and use iterators and other operations on aggregates, including operations that take functions as arguments. 
																//	 I iterate through the aggregate with all the vehicle objects to format and print their names
	std::cout << "Vehicles in Stock" << std::endl;				//	(see take_payment for operation taking function as argument)
	for (int i = 0; i < STOCK_SIZE; i++) {
		std::cout << "\t" << (i + 1) << ". " << stock.at(i).get_name() << std::endl;
	}	// end loop	
}	// end print_stock()


/**
 * @brief function to determine financed price for car
 * @param p (price field of a given car object)
*/
void finance_car(double p) {
	double monthly_price = 0;
	int years = 0;
	double downpayment = 0;
	double remainder = 0;
	
	std::cout << "Would you like to pay the car off in one year or two?(Enter 1 or 2): ";
	std::cin >> years;
	switch (years) {
	case ONE_YEAR:
		downpayment = 0;	// no downpayment for one year
		remainder = p - downpayment;
		monthly_price = remainder / MONTHS_IN_YEAR;
		std::cout << "Because you want to pay in 1 year, we can do payments of $" << monthly_price << " per month with a downpayment of $" << downpayment << "." << std::endl;
		break;
	case TWO_YEARS:
		downpayment = p * TEN_PERCENT;
		remainder = p - downpayment;
		monthly_price = remainder / MONTHS_IN_YEAR;

		std::cout << "Because you want to pay in 2 years, we can do payments of $" << monthly_price << " per month with a down payment of $" << downpayment << "." << std::endl;
		break;
	default:
		std::cout << "Invalid input." << std::endl;
	}
}


/**
 * @brief simulates taking a credit card payment for a car
 * 
 * gets credit card number, expiration date, and cvv code from user and prints to confirm
 		* able to loop back to re-enter information if incorrect
*/
void take_payment() {
	int first_four_dig = 0;
	int second_four_dig = 0;
	int third_four_dig = 0;
	int fourth_four_dig = 0;
	std::string expiration_date;
	int year = 0;
	int month = 0;
	int cvv_code = 0;
	char confirmation = ' ';

	bool entering_info = true;
	while (entering_info) {
		std::cout << "Please enter your credit card number: " << std::endl;
		std::cout << "\nFirst four digits: ";
		std::cin >> first_four_dig;
		std::cout << "\n Next four digits: ";
		std::cin >> second_four_dig;
		std::cout << "\n Next four digits: ";
		std::cin >> third_four_dig;
		std::cout << "\n Next four digits: ";
		std::cin >> fourth_four_dig;
		std::string card_num = std::to_string(first_four_dig) +
			" - " + std::to_string(second_four_dig) + " - " + std::to_string(third_four_dig) + " - " + std::to_string(fourth_four_dig);
		std::cout << "\nNext, enter your card's expiration date: " << std::endl;
		std::cout << "\nYear(_ _ _ _): ";
		std::cin >> year;
		std::cout << "\n Month(_ _): ";
		std::cin >> month;
		//date formatting
		expiration_date = std::to_string(month) + "/" + std::to_string(year);

		if (month < OCTOBER) {
			std::string lowMonth = "0" + std::to_string(month);
			expiration_date = lowMonth + "/" + std::to_string(year);
		}	// hackerrank GET ISO DATE assignment (Professor Vanselow)
		std::cout << "\nPlease enter your 3 digit CVV Code located on the back of your card: ";
		std::cin >> cvv_code;
		std::cout << "\nYou have entered the following information: \n";
		std::cout << "\tCard Number: " << card_num << std::endl;
		std::cout << "\tExpiration Date: " << expiration_date << std::endl;
		std::cout << "\tCVV Code: " << cvv_code << std::endl;
		std::cout << "Is this information accurate? (Enter lowercase y/n): ";
		std::cin >> confirmation;

		if (confirmation == 'y') {
			entering_info = false;
		}

	}

}