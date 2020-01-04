/* 
 * File:   Ticket.h
 * Author: mohamd
 *
 * Created on January 1, 2020, 2:02 PM
 */

#ifndef TICKET_H
#define	TICKET_H

#include "Seat.h"
#include "Organizations.h"
#include <iostream>
#include <vector>
using namespace std;

class Ticket {
public:
    Ticket(string first_name,string last_name , int flight_no ,
                int number_of_persons , int number_of_person_under_12 ,
                    int number_of_persons_under_2 , Seat seat , double price );
    int reserve_code();
    void setReserveCode(int code);
    void toString() ; 
    void setPrice(double price) ;
    int getResCode();
    int getFlightnum() ;
    int getSeatNumber() ;
private:
    string first_name ;
    string last_name ;
    int flight_no ;
    int number_of_persons ;
    int number_of_person_under_12 ;
    int number_of_person_under_2 ;
    int reserveCode ;
    Seat seat ;
    double price ;
    
};

#endif	/* TICKET_H */

