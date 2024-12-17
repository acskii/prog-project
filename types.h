#ifndef TYPES_H
#define TYPES_H

/* Add 
    #include "types.h" 
in program to import these structs 
*/

typedef struct {
    int day, month, year;
} Date;

typedef struct {
    unsigned int id, roomNum;
    unsigned long nationalId;
    int status;         // 0 for unconfirmed, 1 for confirmed
    char mobile[11];    // Count mobile number digits
    Date checkIn;
    char customerName[50];
    int nights;
    char email[200];    // Max was 320, but I think it's too much here
} Reservation;

typedef struct {
    int number, price;
    int status;         // 0 for available, 1 for reserved
    char category[20];  // Could be smaller
} Room;


#endif