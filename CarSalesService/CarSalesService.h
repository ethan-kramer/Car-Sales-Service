/**
 * @file CarSalesService.h
 * @brief main header file for the program
 * 
 * contains constant fields for car objects as well as fields replacing "magic numbers"
 * 
 * @author Ethan Kramer
 * @bug No known bugs.
*/


#ifndef CARSALESSERVICE_H
#define CARSALESSERVICE_H



//Constant fields
//---------------------------------------------------
constexpr int STOCK_SIZE = 5;				// size of in_stock vector
constexpr int RUNNING = 5;					// for program loop flag
constexpr int OCTOBER = 10;					// for expiration date on car in take_payment()
constexpr int STOP_BROWSING = 5;			// to end browse_cars()
constexpr double MONTHS_IN_YEAR = 12.0;		// for date in payment
constexpr double TEN_PERCENT = .1;			// for payment (interest calculation for 2 years)
constexpr int FLAG = 10;					// for menu_choice
constexpr int ONE_YEAR = 1;					// for payment period 
constexpr int TWO_YEARS = 2;				// for payment period 


// Car Cases for Switch Statements
//---------------------------------------------------
constexpr int MAZDA3 = 1;
constexpr int CHEVRY_COLORADO = 2;
constexpr int TOYOTA_CAMRY = 3;
constexpr int HONDA_CIVIC = 4;
constexpr int HYUNDAI_ELANTRA = 5;
constexpr int EXIT = 6;		

constexpr int BROWSE = 1;
constexpr int PURCHASE = 2;


// Mazda3 Stats
//---------------------------------------------------
const std::string MAZDA3_NAME = "2012 Mazda 3";
constexpr double MAZDA3_PRICE = 5000;
constexpr int MAZDA3_MILES = 100000;
constexpr int MAZDA3_ACCIDENTS = 0;
constexpr int MAZDA3_NUM_SEATS = 5;
constexpr int MAZDA3_NUM_DOORS = 4;
constexpr double MAZDA3_TRUNK_SIZE = 13.2;


// Chevy Colorado Stats
//---------------------------------------------------
const std::string CHEVY_COLORADO_NAME = "2016 Chevy Colorado";
constexpr double CHEVY_COLORADO_PRICE = 13000;
constexpr int CHEVY_COLORADO_MILES = 70000;
constexpr int CHEVY_COLORADO_ACCIDENTS = 0;
constexpr int CHEVY_COLORADO_NUM_SEATS = 5;
constexpr int CHEVY_COLORADO_NUM_DOORS = 4;
constexpr double CHEVY_COLORADO_BED_SIZE = 74.4;
constexpr int CHEVY_COLORADO_TOWING_CAPACITY = 7000;


//Toyota Camry Stats
//---------------------------------------------------
const std::string TOYOTA_CAMRY_NAME = "2018 Toyota Camry";
constexpr double TOYOTA_CAMRY_PRICE = 22990;
constexpr int TOYOTA_CAMRY_MILES = 51960;
constexpr int TOYOTA_CAMRY_ACCIDENTS = 0;
constexpr int TOYOTA_CAMRY_NUM_SEATS = 5;
constexpr int TOYOTA_CAMRY_NUM_DOORS = 4;
constexpr double TOYOTA_CAMRY_TRUNK_SIZE = 15.1;


//Honda Civic Stats
//---------------------------------------------------
const std::string HONDA_CIVIC_NAME = "2018 Honda Civic";
constexpr double HONDA_CIVIC_PRICE = 20000;
constexpr int HONDA_CIVIC_MILES = 16000;
constexpr int HONDA_CIVIC_ACCIDENTS = 0;
constexpr int HONDA_CIVIC_NUM_SEATS = 5;
constexpr int HONDA_CIVIC_NUM_DOORS = 4;
constexpr double HONDA_CIVIC_TRUNK_SIZE = 20.1;


//Hyundai Elantra Stats
//---------------------------------------------------
const std::string HYUNDAI_ELANTRA_NAME = "2012 Hyundai Elantra";
constexpr double HYUNDAI_ELANTRA_PRICE = 14000;
constexpr int HYUNDAI_ELANTRA_MILES = 20000;
constexpr int HYUNDAI_ELANTRA_ACCIDENTS = 1;
constexpr int HYUNDAI_ELANTRA_NUM_SEATS = 5;
constexpr int HYUNDAI_ELANTRA_NUM_DOORS = 4;
constexpr double HYUNDAI_ELANTRA_TRUNK_SIZE = 14.8;


#endif