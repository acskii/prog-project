#include <stdio.h>
#include <stdlib.h>
#include "types.h"

/* Andrew Sameh :) */

int compareDates(const void *a, const void *b) {
    // IN ASCENDING ORDER FROM OLDEST TO LATEST
    Reservation* reserveA = (Reservation*)a;
    Reservation* reserveB = (Reservation*)b;

    Date dateA = reserveA->checkIn;
    Date dateB = reserveB->checkIn;

    if (dateA.year != dateB.year) {
        return dateA.year - dateB.year; // Compare by year
    }
    if (dateA.month != dateB.month) {
        return dateA.month - dateB.month; // Compare by month
    }
    return dateA.day - dateB.day; // Compare by day
}

void sortrByDate(Reservation* reservations, int num) {
    // Sorting new array
    qsort(reservations, num, sizeof(Reservation), compareDates);
}

Reservation* rsortrByDate(Reservation* reservations, int num) {
    // New array to return
    Reservation* array = malloc(sizeof(Reservation)*num);
    
    // Filling array
    int i;
    for (i = 0; i < num; i++) {
        array[i] = reservations[i];
    }

    // Sort
    sortrByDate(array, num);

    // Return
    return array;
}