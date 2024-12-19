#ifndef FILE_H
#define FILE_H
#include "types.h"

/*
    There was a bug in both function below (same bug)
    Try to find a solution to it...
    - Andrew Sameh
*/

Reservation* loadReservations(char* fileName, int* count);
Room* loadRooms(char* fileName, int* count);
Staff* loadStaff(char* fileName, int* count);

#endif
