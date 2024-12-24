#ifndef VALIDATE_H
#define VALIDATE_H
#include "types.h"

/* I tried to come up with ways the inputs may be faulty
   and added these countermeasures based on them
   Use these functions in your parts to check if the user input if valid,
   otherwise ask for re-entry

   This is just a check function that returns 1 (valid) or 0 (invalid) 

   Made to fulfill validation requirement in project
*/

int validateRoomNum(int roomNum);
int validateReserveId(int reservationId);
int validateReserveStatus(char* status);
int validateDate(Date date);
int validateMobile(char* mobile);
int validateEmail(char* email);
int validateRoomStatus(char* status);
int validateRoomCategory(char* category);
int validateNationalId(char* nationalId);

#endif