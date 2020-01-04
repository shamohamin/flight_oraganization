/* 
 * File:   Seat.cpp
 * Author: mohamd
 * 
 * Created on January 1, 2020, 2:20 PM
 */

#include "Seat.h"
#include <iostream>
using namespace std;

Seat::Seat(int seat_no, SeatType type):seat_no(seat_no),
            type(type),reserve(0){};
           
           
int Seat::getSeat_no() {
    return this->seat_no ;
};


Seat::Seat(int seat_no, SeatType type, int res):seat_no(seat_no)
    , type(type),reserve(res){};

SeatType Seat::getType() const {
    return this->type ;
};

int Seat::getReserve() const {
    return this->reserve ;
}

void Seat::setReserve(int res){
    this->reserve = res ;
};

void Seat::setType(SeatType type){
    this->type = type;
};
            
 
