#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

/* Andrew Sameh :) */

FILE* readFile(char* fileName) {
    FILE* fp = fopen(fileName, "r");

    if (!fp) {
        printf("%s doesn't exist in same directory", fileName);
        return NULL;
    }
    return fp;
}

Reservation* loadReservations(char* fileName, int* count) {
    // Must be in same directory
    FILE* fp = readFile(fileName);

    Reservation reserves[100];
    int read = 0;
    int records = 0;    // For indexing and malloc

    do {
        char confirmStatus[15];

        // Entire reading here
        read = fscanf(fp,
        "%d,%d,%11[^,],%49[^,],%14s,%d,%d-%d-%d,%199[^,],%11[^\n]\n",
        &reserves[records].id,
        &reserves[records].roomNum,
        confirmStatus,
        &reserves[records].customerName,
        &reserves[records].nationalId,
        &reserves[records].nights,
        &reserves[records].checkIn.day,
        &reserves[records].checkIn.month,
        &reserves[records].checkIn.year,
        reserves[records].email,
        reserves[records].mobile
        );

        reserves[records].status = ((confirmStatus == "unconfirmed") ? 0 : 1);

        if (read == 11) {   // 8 + 3
            // Successful record read
            records++;
        } else {
            // Format error (missing commas)
            /* This works perfectly unless there is an empty line at the end of the txt fiel
                I have no clue on how to fix this...
            */
            printf("Incorrect file format, please fix file content");
            return;
        }
    } while (!feof(fp));

    fclose(fp);

    // Creating array for returning
    Reservation* returnArray = malloc(sizeof(Reservation)*records);
    int i;

    // Copying values from fscanf to new array
    for (i = 0; i < records; i++) {
        returnArray[i].id = reserves[i].id;
        returnArray[i].roomNum = reserves[i].roomNum;
        returnArray[i].status = reserves[i].status;
        strcpy(returnArray[i].customerName, reserves[i].customerName);
        strcpy(returnArray[i].nationalId, reserves[i].nationalId);
        returnArray[i].nights = reserves[i].nights;
        returnArray[i].checkIn.day = reserves[i].checkIn.day;
        returnArray[i].checkIn.month = reserves[i].checkIn.month;
        returnArray[i].checkIn.year = reserves[i].checkIn.year;
        strcpy(returnArray[i].email, reserves[i].email);
        strcpy(returnArray[i].mobile, reserves[i].mobile);
    }

    *count = records;
    return returnArray;
}

Room* loadRooms(char* fileName, int* count) {
    FILE* fp = readFile(fileName);

    Room rooms[100];
    int read = 0;
    int records = 0;    // For indexing and malloc

    do {
        char availableStatus[15];

        // Entire reading here
        read = fscanf(fp,
        "%d %10[^ ] %19[^ ] %d[^\n]\n",
        &rooms[records].number,
        availableStatus,
        &rooms[records].category,
        &rooms[records].price
        );

        rooms[records].status = ((availableStatus == "available") ? 0 : 1);

        if (read == 4) {
            // Successful record read
            records++;
        } else {
            // Format error (missing commas)
            /* This works perfectly unless there is an empty line at the end of the txt fiel
                I have no clue on how to fix this...
            */
            printf("Incorrect file format, please fix file content");
            return;
        }
    } while (!feof(fp));

    fclose(fp);

    // Creating array for returning
    Room* returnArray = malloc(sizeof(Room)*records);
    int i;

    // Copying values from fscanf to new array
    for (i = 0; i < records; i++) {
        returnArray[i].number = rooms[i].number;
        returnArray[i].price = rooms[i].price;
        returnArray[i].status = rooms[i].status;
        strcpy(returnArray[i].category, rooms[i].category);
    }

    *count = records;
    return returnArray;
}

Staff* loadStaff(char* fileName, int* count) {
    FILE* fp = readFile(fileName);

    Staff staff[100];
    int read = 0;
    int records = 0;    // For indexing and malloc

    do {
        // Entire reading here
        read = fscanf(fp,
        "%49[^ ] %19[^\n]\n",
        &staff[records].userName,
        &staff[records].pass
        );

        if (read == 2) {
            // Successful record read
            records++;
        } else {
            // Format error (missing commas)
            /* This works perfectly unless there is an empty line at the end of the txt fiel
                I have no clue on how to fix this...
            */
            printf("Incorrect file format, please fix file content");
            return;
        }
    } while (!feof(fp));

    fclose(fp);

    // Creating array for returning
    Staff* returnArray = malloc(sizeof(Staff)*records);
    int i;

    // Copying values from fscanf to new array
    for (i = 0; i < records; i++) {
        strcpy(returnArray[i].userName, staff[i].userName);
        strcpy(returnArray[i].pass, staff[i].pass);
    }

    *count = records;
    return returnArray;
}

int writeReservations(char* fileName, Reservation* reservations, int num) {
    FILE* fp = fopen(fileName, "w");
    if (!fp) {
        printf("File for writing doesn't exist, '%s'", fileName);   // This line could be done in main thread
        return -1;
    }

    int i;
    for (i = 0; i < num; ++i) {    
        // Convert status of reservation into string
        char statusStr[12];
        if (reservations[i].status) {
            strcpy(statusStr, "comfirmed");
        } else {
            strcpy(statusStr, "uncomfirmed");
        }

        fprintf(
            fp,
            "%d,%d,%s,%s,%s,%d,%d-%d-%d,%s,%s",
            reservations[i].id,
            reservations[i].roomNum,
            statusStr,
            reservations[i].customerName,
            reservations[i].nationalId,
            reservations[i].nights,
            reservations[i].checkIn.day,
            reservations[i].checkIn.month,
            reservations[i].checkIn.year,
            reservations[i].email,
            reservations[i].mobile
        );
        
        if (i < (num - 1)) fputc('\n', fp);
    }
    fclose(fp);
    return 1;
}

int writeRooms(char* fileName, Room* rooms, int num) {
    FILE* fp = fopen(fileName, "w");
    if (!fp) {
        printf("File for writing doesn't exist, '%s'", fileName);   // This line could be done in main thread
        return -1;
    }

    int i;
    for (i = 0; i < num; ++i) {    
        // Convert status of reservation into string
        char statusStr[10];
        if (rooms[i].status) {
            strcpy(statusStr, "Reserved");
        } else {
            strcpy(statusStr, "Available");
        }

        fprintf(
            fp,
            "%d,%s,%s,%d",
            rooms[i].number,
            statusStr,
            rooms[i].category,
            rooms[i].price
        );
        
        if (i < (num - 1)) fputc('\n', fp);
    }
    fclose(fp);
    return 1;
}