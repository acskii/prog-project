#ifndef VALIDATE_H
#define VALIDATE_H
#include "types.h"

int validateRoomNum(int roomNum);
int validateReserveId(int reservationId);
int validateReserseStatus(char* status);
int validateDate(Date date);
int validateMobile(char* mobile);
int validateEmail(char* email);

#endif