#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "types.h"

/* Andrew Sameh :) */

int validateRoomNum(int roomNum) {
    // Only 4 digit integers allowed
    return ((roomNum > 999 && roomNum <= 9999) ? 1 : 0);
}

int validateReserveId(int reservationId) {
    return ((reservationId > 99999 && reservationId <= 999999) ? 1 : 0);
}

int validateReserseStatus(char* status) {
    // Check if status input is either "confirmed" or "unconfirmed"
    int length = strlen(status);
    
    if (length >= 9 && length <= 11) {

        char* clean = status;

        int i;
        for (i = 0; i < length; i++) {
            clean[i] = tolower(clean[i]);
        }

        // Valid status
        return ((strcmp(clean, "confirmed") == 0) || (strcmp(clean, "unconfirmed") == 0));
    }
    // Invalid
    return 0;
}

int validateDate(Date date) {
    if (date.year >= 0) {
        // Non-negative

        switch (date.month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return ((date.day >= 1 && date.day <= 31) ? 1 : 0);
        
        case 4:
        case 6:
        case 9:
        case 11:
            return ((date.day >= 1 && date.day <= 30) ? 1 : 0);

        case 2:
            return ((
                // Leap year
                (
                (
                    (date.year % 4 == 0) || 
                    ((date.year % 400 == 0) && (date.year % 100 != 0))
                ) && 
                (
                    (date.day >= 1) && (date.day <= 29)
                )
                ) || (
                    // Normal
                    (
                        (date.year % 4 != 0) || 
                        (date.year % 400 != 0) 
                    ) 
                    &&
                    ((date.day >= 1) && (date.day <= 28))
                )
            ) ? 1 : 0);

        default:
            break;
        }
    }

    return 0;
}

// ONLY CHECKS EGYPTIAN MOBILE CODES
// DONOT USE OTHERWISE 
int validateMobile(char* mobile) {
    int length = strlen(mobile);

    if (length == 11) {
        // Correct length
        return ((
            (mobile[0] == '0') &&
            (mobile[1] == '1') &&
            (mobile[2] == '0' || mobile[2] == '1' || mobile[2] == '2' || mobile[2] == '5')
        ) ? 1 : 0);
    }
    return 0;
}

// WORK IN PROGRESS
// int validateEmail(char* email) {
// 	char* at = strchr(email, '@');
//     char* dot;

//     // Check if there is an '@' and it's not the first character
//     if (!at || at == email) {
//         return 0;
//     }

//     // Check if there is a '.' after the '@'
//     dot = strchr(at, '.');
//     if (!dot || dot == at + 1) {
//         return 0;
//     }

//     // Check that there are at least two characters after the last '.'
//     if (strlen(dot + 1) < 2) {
//         return 0;
//     }

//     // Check for invalid characters
//     int i;
//     for (i = 0; i < strlen(email); i++) {
//         if (!isalnum(email[i]) && email[i] != '@' && email[i] != '.' && email[i] != '-' && email[i] != '_') {
//             return 0;
//         }
//     }

//     return 1;
// }