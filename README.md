# Programming-1 Repo
I will post my contributions here related to the Final Project for Programming-1 C course
:)

> [!NOTE]
> Watch this [video](https://www.youtube.com/watch?v=idXIb84gsqU) to add header files in CodeBlocks!

## Examples
### main.c example
``` c
#include <stdio.h>
#include <stdlib.h>
#include "types.h"  // contains structs like Reservation, Room
#include "file.h"   // contains load functions

/*
  Both header files are added in same directory as this main.c program
  file.h has prototypes for functions which are defined in the file.c file
  - Andrew
*/

void main() {
    Room* r = loadRooms("./rooms.txt");
    printf("%s", r[3].category);    // LakeView
    
    Reservation* v = loadReservations("./reservations.txt");
    printf("%s", v[1].email);    // mohamed.salah@gmail.com
}
```
### writeReservations example
``` c
#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "file.h"

void main() {
    Date checkInDate = {
        .day = 29,
        .month = 12,
        .year = 2024
    };

    Reservation test = {
        .id = 143256,
        .roomNum = 1124,
        .status = 1,
        .customerName = "Ahmed Mohamed",
        .nationalId = 90022800157646,
        .nights = 4,
        .checkIn = checkInDate,
        .email = "Ahmed.khaled@gmail.com",
        .mobile = "01227653498"
    };

    Reservation test2 = test;
    test2.id = 143266;

    Reservation arr[] = {test, test2};

    printf("Status of write function: %d", writeReservations("./reservations.txt", arr, 2));  // Status of write function: 1
}
```
### reservations.txt 
```
143256,1124,comfirmed,Ahmed Mohamed,285633486,4,29-12-2024,Ahmed.khaled@gmail.com,01227653498
143266,1124,comfirmed,Ahmed Mohamed,285633486,4,29-12-2024,Ahmed.khaled@gmail.com,01227653498
```
## Resources
- Check out this [video](https://www.youtube.com/watch?v=idXIb84gsqU) for header files explanation
- Second answer to this [question](https://stackoverflow.com/questions/20120833/how-do-i-refer-to-a-typedef-in-a-header-file) helped make the `typedef struct`s in type.h
- Check out this [article](https://www.geeksforgeeks.org/header-files-in-c-cpp-and-its-uses/) also for header files 
