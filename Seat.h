/* 
 * File:   Seat.h
 * Author: mohamd
 *
 * Created on January 1, 2020, 2:20 PM
 */

#ifndef SEAT_H
#define	SEAT_H

enum SeatType { ECONOMY = 0 , BUSSINESS , FIRSTCLASS } ;

class Seat {
public:
    Seat(){};
    Seat(int seat_no , enum SeatType type);
    Seat(int seat_no , enum SeatType type , int res) ;
    int getSeat_no();
    SeatType getType() const ;
    int getReserve() const ;
    void setReserve(int res) ;
    void setType(enum SeatType type) ;
private:
    int seat_no ;
    enum SeatType type ;
    int reserve;
};

#endif	/* SEAT_H */

