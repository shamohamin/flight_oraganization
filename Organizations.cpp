/* 
 * File:   Organizations.cpp
 * Author: mohamd
 * 
 * Created on December 31, 2019, 8:02 PM
 */

#include "Organizations.h"
#include "Flight.h"
#include "Ticket.h"
#include "Seat.h"
#include <iostream>
#include <iterator>
#include <cstdlib>
using namespace std;

Organization::Organization(string n,int num) : name(n),num_of_airplanes(num){};
string Organization::getName() const {return this->name ;} ;
int Organization::get_num_of_airplanes() const {return this->num_of_airplanes;};

void Organization::sort_flights(vector<Flight> &flights){
    for(int i = 0 ; i < flights.size() - 1 ; i++){
        for(int j = 0 ; j < flights.size() - 1 ; j++){
            if(flights.at(j).getPrice() > flights.at(j+1).getPrice()){
                Flight temp = flights.at(j + 1) ;
                flights.at(j+1) = flights.at(j) ;
                flights.at(j) = temp ;
            }
        }
    }
};

void ProOrganization::reserve(Flight &flight){
    cout << "enter number of adult person above 12 years old \n" ;
    int number_of_adult_persons ;
    cin >> number_of_adult_persons ;
    int number_of_under_12_years;
    cout << "enter the number of under 12 and older than 2 years old \n";
    cin >> number_of_under_12_years ;
    cout << "enter the number of persons under 2 years old";
    int number_of_under_2 ;
    cin >> number_of_under_2 ;
    while(number_of_adult_persons > 0){
        string first_name ;
        string last_name ;
        
        cout << "enter your first name \n";
        cin >> first_name ;
        cout << "enter your last name \n";
        cin >> last_name ;
        cout << "this are the available seats : \n" ;
        flight.getAvailableSeats() ;
        cout << "choose the one of available seat \n" ;
        int seat_no ;
        cin >> seat_no ;
        if(flight.checkTheSeat(seat_no)){
            double price = flight.getPrice();
            Seat seat ;
            if(flight.getType() == ECONOMYCLASS)
                seat = Seat(seat_no , ECONOMY , true) ;
            else if(flight.getType() == ROYAL) 
                seat = Seat(seat_no , FIRSTCLASS , true) , price = price + price * 0.2;
            else {
                cout << "enter your seat Type \n";
                cout << "1.economy \n";
                cout << "2.business \n";
                cout << "3.first class \n";
                int option ;
                cin >> option ;
                if (option == 1) seat = Seat(seat_no , ECONOMY , true) ;
                else if(option == 2) seat = Seat(seat_no , BUSSINESS , true) , price = price + price * 0.1 ;
                else seat = Seat(seat_no , FIRSTCLASS , true) , price = price + price * 0.2;
            }
            Ticket ticket = Ticket(first_name,last_name,flight.getFlightNumber(),
                            1 , 0 , number_of_under_2 , seat, price) ;
            ticket.setReserveCode(ticket.reserve_code()) ;
            ticket.toString() ;
//            flight.change_seat_status(seat_no , 1 , seat.getType()) ;
            this->insert_ticket(ticket) ;
            flight.insertSeat(seat) ;
            number_of_adult_persons-- ;
        }else{
            cout << "seat is not available !!!";
            break;
        }
    }
    
    while(number_of_under_12_years > 0){
        string first_name ;
        string last_name ;
        
        cout << "enter your first name \n";
        cin >> first_name ;
        cout << "enter your last name \n";
        cin >> last_name ;
        cout << "this are the available seats : \n" ;
        flight.getAvailableSeats() ;
        cout << "choose the one of available seat \n" ;
        int seat_no ;
        cin >> seat_no ;
        if(flight.checkTheSeat(seat_no)){
            double price = flight.getPrice();
            Seat seat ;
            if(flight.getType() == ECONOMYCLASS)
                seat = Seat(seat_no , ECONOMY , true) ;
            else if(flight.getType() == ROYAL) 
                seat = Seat(seat_no , FIRSTCLASS , true) , price = price + price * 0.2;
            else {
                cout << "enter your seat Type \n" ;
                cout << "1.economy \n" ;
                cout << "2.business \n" ;
                cout << "3.first class \n" ;
                int option ;
                cin >> option ;
                if (option == 1) seat = Seat(seat_no , ECONOMY , true) ;
                else if(option == 2) seat = Seat(seat_no , BUSSINESS , true) , price = price + price * 0.1 ;
                else seat = Seat(seat_no , FIRSTCLASS , true) , price = price + price * 0.2;
            }

            Ticket ticket = Ticket(first_name,last_name,flight.getFlightNumber(),
                            0 , 1 , 0 , seat, price) ;
            ticket.setReserveCode(ticket.reserve_code()) ;
            ticket.toString() ;
            this->insert_ticket(ticket) ;
//            flight.change_seat_status(seat_no , 1 , seat.getType()) ;
            flight.insertSeat(seat) ;
            number_of_under_12_years-- ;
        }else{
            cout << "seat is reserved !!! \n" ; 
            break ;
        }
    }
};


void NewOrganization::reserve(Flight &flight){
    cout << "enter number of adult person above 12 years old \n" ;
    int number_of_adult_persons ;
    cin >> number_of_adult_persons ;
    int number_of_under_12_years;
    cout << "enter the number of under 12 and older than 2 years old \n";
    cin >> number_of_under_12_years ;
    cout << "enter the number of persons under 2 years old";
    int number_of_under_2 ;
    cin >> number_of_under_2 ;
    while(number_of_adult_persons > 0){
        string first_name ;
        string last_name ;
        cout << "enter your first name \n" ;
        cin >> first_name ;
        cout << "enter your last name \n" ;
        cin >> last_name ;
        cout << "this are the available seats : \n" ;
        flight.getAvailableSeats() ;
        cout << "choose the one of available seat \n" ;
        int seat_no ;
        cin >> seat_no ;
        if(flight.checkTheSeat(seat_no)){
            Seat seat = Seat(seat_no , ECONOMY , true) ;
            Ticket ticket = Ticket(first_name,last_name,flight.getFlightNumber(),
                            1,0,number_of_under_2,seat,flight.getPrice()) ;
            ticket.setReserveCode(ticket.reserve_code()) ;
            ticket.toString() ;
            this->insert_ticket(ticket) ;
//            flight.change_seat_status(seat_no , 1 , seat.getType()) ;
            flight.insertSeat(seat) ;
            number_of_adult_persons-- ;
        }else{
            cout << "seat is not Available !!!\n";
            break ;
        }
    }
    
    while(number_of_under_12_years > 0){
        string first_name ;
        string last_name ;
        cout << "enter your first name \n" ;
        cin >> first_name ;
        cout << "enter your last name \n" ;
        cin >> last_name ;
        cout << "this are the available seats : \n" ;
        flight.getAvailableSeats() ;
        cout << "choose the one of available seat \n" ;
        int seat_no ;
        cin >> seat_no ;
        if(flight.checkTheSeat(seat_no)){
            Seat seat = Seat(seat_no , ECONOMY , true) ;
            Ticket ticket = Ticket(first_name,last_name,flight.getFlightNumber(),
                            0, 1 , number_of_under_2 , seat,flight.getPrice()) ;
            ticket.setReserveCode(ticket.reserve_code()) ;
            ticket.toString() ;
//            flight.change_seat_status(seat_no , 1 , seat.getType()) ;
            flight.insertSeat(seat) ;
            number_of_under_12_years-- ;
        }else{
            cout << "seat is not available !! \n";
            break ;
        }
        
    }
    
};

NewOrganization NewOrganization::make_organization(){
    string name ;
    cout << "enter name of organization \n" ;
    cin >> name ;
    cout << "enter number of airplanes of organization \n" ;
    int num ;
    cin >> num ;
    NewOrganization no = NewOrganization(name , num) ;
    return no ;
};

ProOrganization ProOrganization::make_newOrganization(){
    string name ;
    cout << "enter name of organization \n" ;
    cin >> name ;
    cout << "enter number of airplanes of organization \n" ;
    int num ;
    cin >> num ;
    ProOrganization po = ProOrganization(name , num) ;
    return po ;
};

void Organization::insert_ticket(Ticket ticket){
    this->tikects.push_back(ticket) ;
}

void Organization::deleteTicket_cancelTicket(int resCode ,vector<Flight> flights){
    vector<Ticket>::iterator itr = this->tikects.begin() ,
                itr2 = this->tikects.begin() ;
    int flight_no ;
    bool flag ;
    int seat_no ;
    for(int i = 0 ; i < this->tikects.size() ; i++){
        if(tikects[i].getResCode() == resCode){
            flag = true ;
            flight_no = tikects[i].getFlightnum() ;
            seat_no = tikects[i].getSeatNumber();
            advance(itr , i) ;
            advance(itr2 , i+1) ;
            this->tikects.erase(itr , itr2) ;
            break ;
        }
    }
    
    if(flag){
    
        for(int i = 0 ; i < flights.size() ; i++){
            if(flights.at(i).getFlightNumber() == flight_no){
                flights.at(i).change_seat_status(seat_no , false , ECONOMY) ;
            }
        }
    }else {
        cout << "not such flight !!!!!!!!!!!\n" ;
    }
    
    
}
