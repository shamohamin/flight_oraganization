/* 
 * File:   main.cpp
 * Author: mohammdAmin shafiee
 *
 * Created on December 31, 2019, 8:00 PM
 */

#include <cstdlib>
#include <iostream>
#include "Organizations.h"
#include "Flight.h"
#include <vector>
using namespace std;

vector<NewOrganization> newOrganizations ;
vector<ProOrganization> proOrganizations ;
vector<Flight> flights ;

void show_menu() ;
void show_organization() ;
void search();
void reserve();
void insert_date_for_search(int option);

/*
 * 
 */
int main(int argc, char** argv) {
    while (1){
        show_menu();
        int option ;
        cin >> option ;

        switch (option)
        {
        case 1:
            cout << "press 1 for pro_organization 2 for new_organization \n" ;
            int option ;
            cin >> option ;
            if(option == 1){
                ::proOrganizations.push_back(ProOrganization().make_newOrganization());
                break ;
            }
            ::newOrganizations.push_back(NewOrganization().make_organization()) ;
            break;
        case 2:
            flights.push_back(Flight().make_flight(proOrganizations , newOrganizations)) ; 
            if(flights.front().getOrganizationName().compare("") == 0){
                flights.pop_back() ;
            }
            break ;   
        case 3:
            show_organization();
            break ;
        case 4:
            search();
            break ;
        case 5:
            reserve();
            break;
        case 6:
            exit(1);
        default:
            break;
        }
    }
    return 0;
}

void show_menu(){
    cout << "********************************************************" << endl ;
    cout << "press 1 to add organization \n";
    cout << "press 2 to declare flight \n"; 
    cout << "press 3 for showing organization \n" ;
    cout << "press 4 search \n" ;
    cout << "press 5 for reserve Ticket \n" ;
    cout << "*********************************************************" << endl ;
}

void search_menu() {
    cout << "********************************************************" << endl ;
    cout << "press 1 to search by origin \n";
    cout << "press 2 to search by destination \n";
    cout << "press 3 to search by organization name \n"; 
    cout << "press 4 show all flights \n" ;
    cout << "press 5 to search by time and Date of departure \n";
    cout << "press 6 to search by time and Date of arrival \n" ;
    cout << "press 7 to exit search menu \n" ;
    cout << "*********************************************************" << endl ;
}

void search(){
    bool flag = false ;
    Organization().sort_flights(flights) ;
    while(1){
        
        if(flag)
            break ;
        
        search_menu() ;
        int option ;
        cin >> option ;
        switch(option)
        {
        case 1:{
            cout << "enter name of destination ? \n" ;
            string name ;
            cin >> name ;
            if(!Flight().search_by_origin_or_destination(1 , flights , name)){
                cout << "nothing found ||!!!?? \n" ;
            }
            break;
        }
        case 2:{
            cout << "enter name of origin ? \n" ;
            string des_name ;
            cin >> des_name ;
            if(!Flight().search_by_origin_or_destination(2 , flights ,des_name)){
                cout << "nothing found !!!" << endl ;
            }
            break;
        }
        case 3:{
            cout << "enter organization name \n";
            string name ;
            cin >> name ;
            for(int i = 0 ; i < flights.size() ; i ++){
                if(flights.at(i).getOrganizationName().compare(name) == 0)
                    flights.at(i).toString();
            }
            break ;
        }
        case 4:
            for(int i = 0 ; i < flights.size() ; i++){
                flights.at(i).toString() ;
            }
            break;
            case 5:
                insert_date_for_search(1) ;
                break ;
            case 6:
                insert_date_for_search(2) ;
                break;
        case 7:
            flag = true ;
            break;
        }
    }
}

void show_organization(){
    cout << "this is the list of pro Organization \n" ;
    for(int i = 0 ; i < proOrganizations.size() ; i++)
        cout << "the name is : " <<proOrganizations[i].getName() << 
                        endl << "the number of airplanes is : " << 
                    proOrganizations[i].get_num_of_airplanes() << endl << "*******\n" ;
    cout << "this is the list of new Organization \n" ;
    for(int i = 0 ; i < newOrganizations.size() ; i++)
        cout << "the name is : " <<newOrganizations[i].getName() << 
                        endl << "the number of airplanes is : " << 
                    newOrganizations[i].get_num_of_airplanes() << endl << "*******\n" ;
}

void reserve(){
    cout << "input the flight number \n" ;
    int flight_no ;
    cin >> flight_no ;
    bool flag = false ;
    for(int i = 0 ; i < flights.size() ; i++){
        if(flights[i].getFlightNumber() == flight_no){
            flag = true ;
            for(int j = 0 ; j < proOrganizations.size() ; j++){
                if(proOrganizations[j].getName().compare(flights[i].getOrganizationName()) == 0){
                    proOrganizations[j].reserve(flights[i]);
                    break;
                }
            }
            for(int j = 0 ; j < newOrganizations.size() ; j++){
                if(newOrganizations[j].getName().compare(flights[i].getOrganizationName()) == 0){
                    newOrganizations[j].reserve(flights[i]);
                    break;
                }
            }
            break ;
        }
    }
    
    if(!flag) cout << "not such flight number \n" ;
}


void insert_date_for_search(int option){
    int start_year , start_month , start_day ;
    int end_year , end_month , end_day ; 
    cout << "insert your first year \n";
    cin >> start_year;
    cout << "insert your first month \n";
    cin >> start_month ;
    cout << "insert your first Day \n" ;
    cin >> start_day;
    cout << "insert your end year \n";
    cin >> end_year;
    cout << "insert your end month \n";
    cin >> end_month ;
    cout << "insert your end Day \n" ;
    cin >> end_day;
    int start_hour , start_minute ;
    int end_hour , end_minute ;
    cout << "insert start Hour \n";
    cin >> start_hour;
    cout << "insert start minute \n";
    cin >> start_minute ;
    cout << "insert end Hour \n";
    cin >> end_hour;
    cout << "insert end minute \n";
    cin >> end_minute ;
    Time start_time = Time(start_hour , start_minute) ;
    Time end_time = Time(end_hour , end_minute);
    Date start_date = Date(start_year , start_month , start_day) ;
    Date end_date = Date(end_year , end_month , end_day) ;
    vector<Flight> fli = Flight().search_by_time_date(flights ,start_time ,
                end_time , start_date , end_date , option );
    for(int i = 0 ; i < fli.size() ; i++ ){
        fli[i].toString() ;
    }
}

