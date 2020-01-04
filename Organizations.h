/* 
 * File:   Organizations.h
 * Author: mohamd
 *
 * Created on December 31, 2019, 8:02 PM
 */

#ifndef ORGANIZATIONS_H
#define	ORGANIZATIONS_H


#include "Ticket.h"
#include "Seat.h"
#include <iostream>
#include <iterator>
#include <vector>
#include "Flight.h"
class Flight;
class Ticket;

using namespace std;

enum type { PRO = 0 , NEW } ;

class Organization {
public:
    Organization(string n,int num);
    Organization(){};
    string getName() const;
    int get_num_of_airplanes() const ;
    int getType() const {return 0 ;} ;
    void insert_ticket(Ticket ticket) ;
    static void sort_flights(vector<Flight> &flights) ;
    void deleteTicket_cancelTicket(int resCode , vector<Flight> flights) ;
private:
    string name ;
    int num_of_airplanes;
    vector<Ticket> tikects; 
};


class NewOrganization:public Organization{
private:
    int type;
public:
    NewOrganization(string name , int num):type(NEW),Organization(name , num){} ;
    NewOrganization():Organization(){} ;
    int getType() const {return this->type;} ; 
    static NewOrganization make_organization() ;
    void reserve(Flight &flight);
};


class ProOrganization:public Organization {
private:
    int type;
public:
    ProOrganization(string name , int num):type(PRO),Organization(name , num){};
    ProOrganization():Organization(){};
    int getType() const {return this->type ;} ; 
    static ProOrganization make_newOrganization();
    void reserve(Flight &flight) ;
};



#endif	/* ORGANIZATIONS_H */

