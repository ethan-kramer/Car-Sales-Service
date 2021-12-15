/**
 * @file Truck.h
 * @brief header file for class Truck
 *
 * Contains fields, constructors and methods for truck objects
 *
 * @author Ethan Kramer
 * @bug No known bugs.
*/


#ifndef TRUCK_H
#define TRUCK_H


#include "Vehicle.h"
class Truck :
    public Vehicle
{
private:    // ENCAPSULATION: private and public fields/members
    double bed_size;
    int towing_capacity;

public:
    //setters
    //------------------------------------------------------------------------------------
    void set_bed_size(double s) noexcept { bed_size = s; }
    void set_towing_capacity(int c) noexcept {towing_capacity = c; }


    //getters
    //------------------------------------------------------------------------------------
    auto get_bed_size() noexcept -> double { return bed_size; }
    int get_towing_capacity() noexcept { return towing_capacity; }


    //constructors
    //------------------------------------------------------------------------------------
    Truck() noexcept {
        bed_size = 0.0;
        towing_capacity = 0;
    }  //default constructor


    //LO1b.Overload a constructor
    //LO1c.Utilize an initialization list
    Truck(std::string n, double p, int m, int a, int s, int d, double bs, int tc) {
        set_name(n);
        set_price(p);
        set_miles(m);
        set_accidents(a);
        set_num_seats(s);
        set_num_doors(d);
        set_bed_size(bs);
        set_towing_capacity(tc);    
    }   //overloaded constructor


    //----------------------------------------------------------------------------------------------------------------------------------------------------------

    //methods

    //----------------------------------------------------------------------------------------------------------------------------------------------------------
    /**
     * @brief prints stats of car (the object type calling function determines which print_stats() is used)
     * 
     * LO3. Correctly reason about control flow in a program using dynamic dispatch. 
    */
    void print_stats() override {
        std::cout << get_name() << std::endl;
        std::cout << "\t Price: $" << get_price() << std::endl;
        std::cout << "\t Miles: " << get_miles() << std::endl;
        std::cout << "\t Accidents: " << get_accidents() << std::endl;
        std::cout << "\t Transmission Type: Automatic" << std::endl;
        std::cout << "\t Number of Seats: " << get_num_seats() << std::endl;
        std::cout << "\t Number of Doors: " << get_num_doors() << std::endl;
        std::cout << "\t Leather Seats: No" << std::endl;
        std::cout << "\t Bed Size: " << get_bed_size() << "''" << std::endl;
        std::cout << "\t Towing Capacity: " << get_towing_capacity() << std::endl;
    }
};

#endif