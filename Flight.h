/* 
 * File:   Flight.h
 * Author: mohamd
 *
 * Created on December 31, 2019, 8:10 PM
 */

#ifndef FLIGHT_H
#define	FLIGHT_H


#include "Organizations.h"
#include "Seat.h"
#include <iostream>
#include <vector>
using namespace std;
class NewOrganization ;
class ProOrganization ;

struct Date {
    int year ;
    int month ;
    int day ;
    Date(int year , int month , int day):year(year) , month(month) , day(day){};
    Date(){} ;
    static bool check(int year , int month , int day){
        if(month > 0 && month <= 12 && day <= 31 && day > 0)
            return true ;
        return false ;
    };
};

struct Time {
    int hour ;
    int minute ;
    Time(int hour , int minute){
        this->hour = hour ;
        this->minute = minute ;
    };
    Time(){} ;
    static bool check(int hour , int minute){
        if(hour < 25 && hour > 0 && minute >= 0 && minute < 60)
            return true;
        return false ;
    };
};

enum Type {ECONOMYCLASS , FIRST , ROYAL} ;

class Flight {
public:
    Flight(){};
    Flight(string n , int f , string d , string o ,
            Date d_d , Date l_d , Time d_t , Time a_t , double p , int num ,
            int type ):
            organization_name(n) , flight_no(f) , destination(d) , origin(o) ,
            departure_date(d_d) , landing_date(l_d) , departure(d_t) , arrival(a_t) ,
            price(p) , number_of_members(num) {
            
            if(type == 1) this->type = ECONOMYCLASS ;
            else if (type == 2) this->type = FIRST ;
            else this->type = ROYAL ;
        };
      
            static Flight make_flight(vector<ProOrganization> p ,
                    vector<NewOrganization> n) ;
            static bool cheker(vector<ProOrganization> p , 
                    vector<NewOrganization> n , string name) ;
            void toString();
            static bool  search_by_origin_or_destination(int option ,
                        vector<Flight> flights , string name);
            
            string getOrganizationName() const {
                return this->organization_name ;
            };

            string getDestinationName() const {
                return this->destination ;
            };

            string getOrigin() const ;
            Date getDepartureDate() const {return this->departure_date ;};
            Date getArrivalDate() const {return this->landing_date ;} ;
            Time getArrivalTime() const {return this->arrival ;} ;
            Time getDepartureTime() const {return this->departure ;};
            int getFlightNumber() const {return this->flight_no ;};
            void getAvailableSeats();
            double getPrice() const {return this->price;};
            void insertSeat(Seat seat);
            void change_seat_status(int seat_no , int status , SeatType type);
            Type getType() const {return this->type ; };
            static vector<Flight> search_by_time_date(vector<Flight>flights ,
                Time first , Time last , Date first_d , Date last_d,int option);
            bool checkTheSeat(int seat_no) ;
            bool checkForEmptySeat() ;
            
private:
    string organization_name ;
    int flight_no ;
    string destination ;
    string origin ;
    Date departure_date ;
    Date landing_date ;
    Time departure ;
    Time arrival ;
    double price ;
    int number_of_members ;
    vector<Seat> seats ;
    enum Type type ; 
};

#endif	/* FLIGHT_H */

