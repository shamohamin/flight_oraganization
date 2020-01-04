/* 
 * File:   Ticket.cpp
 * Author: mohamd
 * 
 * Created on January 1, 2020, 2:02 PM
 */

#include <string>
#include <iostream>
#include "Ticket.h"
#include "Seat.h"
#include "Organizations.h"
using namespace std;

int Ticket::reserve_code(){
    int hash = 0 ;
    for(int i = 0 ; i < this->first_name.length() ; i++)
        hash += (int)first_name[i] ;
    for(int i = 0 ; i < this->last_name.length() ; i++)
        hash += (int)last_name[i] ;
    return hash;
};

void Ticket::setReserveCode(int code){
    this->reserveCode = code ;
};

int Ticket::getFlightnum(){
    return this->flight_no ;
};

int Ticket::getSeatNumber(){
    return this->seat.getSeat_no();
};

void Ticket::setPrice(double price){
    this->price = price ;
};

void Ticket::toString(){
    cout << "the first name is : " << this->first_name << std::endl ;
    cout << "the last name is : " << this->last_name << std::endl ;
    cout << "the price is : " << this->price << std::endl ;
    cout << "the number of adult person is : " << this->number_of_persons << std::endl ;
    cout << "the number of person under 12 is : " << this->number_of_person_under_12 << std::endl ;
    cout << "the number of person under 2 is : " << this->number_of_person_under_2 << std::endl ;
    cout << "the reserve code is : " << this->reserveCode << std::endl ; 
    cout << "the seat number is : " << this->seat.getSeat_no() << std::endl ;
    cout << "the seat type is : " << this->seat.getType() << std::endl ;
};
int Ticket::getResCode(){
    return this->reserveCode ;
}

Ticket::Ticket(string first_name, string last_name, int flight_no,
            int number_of_persons, int number_of_person_under_12,
            int number_of_persons_under_2 ,Seat seat , double price):
        first_name(first_name),price(price),
        last_name(last_name) , flight_no(flight_no) ,
        number_of_persons(number_of_persons),
        number_of_person_under_12(number_of_person_under_12),
        number_of_person_under_2(number_of_persons_under_2) , seat(seat) {};

        