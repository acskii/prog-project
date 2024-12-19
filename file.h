#ifndef FILE_H
#define FILE_H
#include "types.h"

/*
    There was a bug in both function below (same bug)
    Try to find a solution to it...
    - Andrew Sameh
*/

Reservation* loadReservations(char* fileName, int* count);
// Return: 1 for done, -1 for error // Parameters: Name of file to write reservations, array of Reservation structs, number of structs in array
int writeReservations(char* fileName, Reservation* reservations, int* num);     
Room* loadRooms(char* fileName, int* count);
int writeRooms(char* fileName, Room* rooms, int num);
Staff* loadStaff(char* fileName, int* count);

#endif
