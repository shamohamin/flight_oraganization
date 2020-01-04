/* 
 * File:   Flight.cpp
 * Author: mohamd
 * 
 * Created on December 31, 2019, 8:10 PM
 */


#include "Flight.h"
#include "Organizations.h"
#include "Seat.h"
#include <iostream>
#include <vector>
using namespace std ;
class Seat;

Flight Flight::make_flight(vector<ProOrganization> p, vector<NewOrganization> n){
     cout << "enter name of organization ? \n" ;
        string name ;
        cin >> name ;
        if (!cheker(p , n , name)){
            cout << "no such organization try again \n" ;
            return Flight() ;
        }
        cout << "enter flight number \n";
        int num ;
        cin >> num ;
        string des ;
        cout << "enter name of destination \n" ;
        cin >> des ;
        cout << "enter name of origin \n";
        string ori ;
        cin >> ori ;
        Date departure , arrival ;
        while (1)
        {
            int year , month , day ;
            cout << "enter year of departure \n" ;
            cin >> year ;
            cout << "enter month of departure \n" ;
            cin >> month ;
            cout << "enter day of departure \n" ;
            cin >> day ;
            if(Date().check(year , month , day)){
                departure = Date(year , month , day) ;
                break ;
            }
            else 
                cout << "enter right Date try again \n";
        }
        while (1)
        {
            int year , month , day ;
            cout << "enter year of arrival \n" ;
            cin >> year ;
            cout << "enter month of arrival \n" ;
            cin >> month ;
            cout << "enter day of arrival \n" ;
            cin >> day ;
            if(Date().check(year , month , day)){
                arrival = Date(year , month , day) ;
                break ;
            }
            else 
                cout << "enter right Date try again \n";
        }

        Time departure_time , arrival_time ; 

        while (1)
        {
            int hours , minutes ;

            cout << "enter the hours of departure \n" ;
            cin >> hours ;
            cout << "enter the minutes of departure \n" ;
            cin >> minutes ;

            if(Time().check(hours , minutes)){
                departure_time = Time(hours , minutes) ;
                break;
            }else 
                cout << "enter the right time try again \n" ;
        }
        
        while (1)
        {
            int hours , minutes ;

            cout << "enter the hours of arrival  \n" ;
            cin >> hours ;
            cout << "enter the minutes of arrival \n" ;
            cin >> minutes ;

            if(Time().check(hours , minutes)){
                arrival_time = Time(hours , minutes) ;
                break;
            }else 
                cout << "enter the right time try again \n" ;
        }
        double price ;
        int number_of_members ;
        cout << "enter price of flight \n" ;
        cin >> price ;
        cout << "enter the number of members or seats \n" ;
        cin >> number_of_members ;
        cout << "enter the type of flight \n" ;
        cout << "1.economy \n";
        cout << "2.first class \n";
        cout << "3.royal \n";
        int type ;
        cin >> type ;
        Flight flight = Flight(name , num ,des , ori ,
                departure , arrival,departure_time,arrival_time 
                , price , number_of_members , type ) ;
        
        return flight ;
}



bool Flight::cheker(vector<ProOrganization> p, vector<NewOrganization> n,
            string name){
    cout << "outout name : " << name << endl ;
    for(int i = 0 ; i < p.size() ; i++ ){
        if (p.at(i).getName().compare(name) == 0){
            return true ;
        }
    }

    for(int i = 0 ; i < n.size() ; i++ ){
        if (n.at(i).getName().compare(name) == 0){
            return true ;
        }
    }
    
    return false ;
};

void Flight::toString(){
    cout << "*****************************************************" << endl;
    cout << "the or : " << this->organization_name << endl ;
    cout << "the destination: " << this->destination << endl ;
    cout << "the origin: " << this->origin << endl;
    cout << "the flight_no: " << this->flight_no << endl ;
    cout << "the price is:" << this->price << endl;
    cout << "time arrival:  " << this->arrival.hour << ":" << this->arrival.minute << endl;
    cout << "the departure time is : " << this->departure.hour << ":" << this->departure.minute << endl ;
    cout << "the departure date is : " << this->departure_date.year << ":" << this->departure_date.month << ":" << this->departure_date.day << endl ;
    cout << "the landing date is : " << this->landing_date.year << ":" << this->landing_date.month << ":" << this->landing_date.day << endl ;
    cout << "*****************************************************" << endl;
};

bool Flight::search_by_origin_or_destination(int option, vector<Flight> flights, string name){
    bool flag = false ;
    if(option == 1){
        for(int i = 0 ; i < flights.size() ; i++){
            if(name.compare(flights[i].getDestinationName()) == 0){
                flights[i].toString() ;
                flag = true ;
            }
        }
    }else {
        for(int i = 0 ; i < flights.size() ; i++){
            if(name.compare(flights[i].getOrigin()) == 0){
                flights[i].toString() ;
                flag = true ;
            }
        }
    }
    return flag ;
};

vector<Flight> Flight::search_by_time_date(vector<Flight> flights ,Time first,
            Time last, Date first_d , Date last_d , int option){
    
    
    vector<Flight> hold_depature_flights ;
    vector<Flight> hold_Arrival_flights ;
    for(int i = 0 ; i < flights.size() ; i++){
        if(first_d.year < flights[i].getDepartureDate().year && flights[i].getDepartureDate().year <= last_d.year)
            hold_depature_flights.push_back(flights[i]);
        else if (first_d.year == flights[i].getDepartureDate().year){
            if(first_d.month < flights[i].getDepartureDate().month && last_d.month >= flights[i].getDepartureDate().month)
                hold_depature_flights.push_back(flights[i]) ;
            else if (first_d.month == flights[i].getDepartureDate().month){
                if(first_d.day < flights[i].getDepartureDate().day && last_d.day >= flights[i].getDepartureDate().day)
                    hold_depature_flights.push_back(flights[i]);
                else if (first_d.day == flights[i].getDepartureDate().day){
                    if(first.hour < flights[i].getDepartureTime().hour && last.hour >= flights[i].getDepartureTime().hour)
                        hold_depature_flights.push_back(flights[i]) ;
                    else if(first.hour == flights[i].getDepartureTime().hour){
                        if(first.minute < flights[i].getDepartureTime().minute && flights[i].getDepartureTime().minute <= last.minute)
                            hold_depature_flights.push_back(flights[i]) ; 
                    }
                }
            }
        }
    }
    
    for(int i = 0 ; i < flights.size() ; i++){
        if(first_d.year < flights[i].getArrivalDate().year && flights[i].getArrivalDate().year <= last_d.year)
            hold_Arrival_flights.push_back(flights[i]);
        else if (first_d.year == flights[i].getArrivalDate().year){
            if(first_d.month < flights[i].getArrivalDate().month && last_d.month >= flights[i].getArrivalDate().month)
                hold_Arrival_flights.push_back(flights[i]) ;
            else if (first_d.month == flights[i].getArrivalDate().month){
                if(first_d.day < flights[i].getArrivalDate().day && last_d.day >= flights[i].getArrivalDate().day)
                    hold_Arrival_flights.push_back(flights[i]);
                else if (first_d.day == flights[i].getArrivalDate().day){
                    if(first.hour < flights[i].getArrivalTime().hour && last.hour >= flights[i].getArrivalTime().hour)
                        hold_Arrival_flights.push_back(flights[i]) ;
                    else if(first.hour == flights[i].getArrivalTime().hour){
                        if(first.minute < flights[i].getArrivalTime().minute && flights[i].getArrivalTime().minute <= last.minute)
                            hold_Arrival_flights.push_back(flights[i]) ; 
                    }
                }
            }
        }
    }
    
    if(option == 1)
        return hold_depature_flights ;
    
    return hold_Arrival_flights ;
};

string Flight::getOrigin() const {
    return this->origin ; 
};


void Flight::getAvailableSeats(){
    
    cout << "[ ";
    
    for(int j = 1 ; j <= this->number_of_members ; j++){
        bool flag = false ;
        for (int i = 0 ; i < this->seats.size() ; i++ ){
            if(this->seats.at(i).getSeat_no() == j){
                flag = true ;
                break;
            }
        }
        if(!flag) cout << j << "," ;
    }
    cout << " ]";
    
};

void Flight::insertSeat(Seat seat){
    cout << "hello   " ;
    this->seats.push_back(seat) ;
    
    for(int i = 0 ; i < this->seats.size() ; i++)
        cout << this->seats.at(i).getSeat_no() << endl ;
};


bool Flight::checkTheSeat(int seat_no){
    for(int i = 0 ; i < this->seats.size() ; i++){
        if(this->seats.at(i).getSeat_no() == seat_no)
            return false ;
    }
    return true ;
};

bool Flight::checkForEmptySeat(){
    return this->seats.size() == this->number_of_members ;
}

void Flight::change_seat_status(int seat_no, int status , SeatType seatType){
    for (int i = 0 ; i < this->seats.size() ; i++){
        if(this->seats.at(i).getSeat_no() == seat_no){
            cout << "hello ************* " << status << endl; 
            Seat seat = ((this->seats).at(i)) ;
            seat.setReserve(status) ;
            seat.setType(seatType) ;
            break ;
        }
    }
}


