# Programming-1 Repo
I will post my contributions here related to the Final Project for Programming-1 C course
:)

> [!NOTE]
> Watch this [video](https://www.youtube.com/watch?v=idXIb84gsqU) to add header files in CodeBlocks!

## Validation
> [!TIP]
> Try these test cases, and add your own test cases as well
> If any of these test cases fail, please inform me / suggest a solution yourself
```c
 // Test cases for date validation
    Date leapYearDate = {29,2,2024};
    Date normalWFebDate = {29,2,2023};
    Date normalRFebDate = {28,2,2023};
    Date above31 = {32,4,2023};
    Date yearNegative = {32,4,-90};
    Date dayNegative = {32,-4,90};
    Date monthNegative = {-32,4,90};
    Date month30day31 = {31,4,2020};
    Date month31day31 = {31,1,2020};
    Date wrongMonth = {31,13,2020};
    Date normalDate = {13,6,2020};
    Date nullDate = {0,0,0};

    printf("Normal Date: %d\n", validateDate(normalDate));
    printf("Leap Year: %d\n", validateDate(leapYearDate));
    printf("Normal February Wrong: %d\n", validateDate(normalWFebDate));
    printf("Normal February Right: %d\n", validateDate(normalRFebDate));
    printf("Day above 31: %d\n", validateDate(above31));
    printf("Negative Year: %d\n", validateDate(yearNegative));
    printf("Negative Day: %d\n", validateDate(dayNegative));
    printf("Negative Month: %d\n", validateDate(monthNegative));
    printf("Day 31 with April: %d\n", validateDate(month30day31));
    printf("Day 31 with January: %d\n", validateDate(month31day31));
    printf("Wrong month: %d\n", validateDate(wrongMonth));
    printf("0-0-0 Date: %d\n", validateDate(nullDate));

    printf("\nMobile 017: %d\n", validateMobile("01737653498"));
    printf("\nMobile 010: %d\n", validateMobile("01037653498"));
    printf("\nMobile 012: %d\n", validateMobile("01237653498"));
    printf("\nMobile 011: %d\n", validateMobile("01137653498"));
    printf("\nMobile 015: %d\n", validateMobile("01537653498"));
    printf("\nMobile Wrong Length: %d\n", validateMobile("0103653498"));

```

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
### Reservation Sorting example
```c
#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "file.h"
#include "sort.h"

void main() {
    Reservation test1 = {
        .id = 143256,
        .roomNum = 1124,
        .status = 1,
        .customerName = "Ahmed Mohamed",
        .nationalId = "90022800157646",
        .nights = 4,
        .checkIn = {
            .day = 29,
            .month = 12,
            .year = 2024
        },
        .email = "Ahmed.khaled@gmail.com",
        .mobile = "01227653498"
    };

    Reservation test2 = {
        .id = 142347,
        .roomNum = 1110,
        .status = 0,
        .customerName = "Omar Ahmed",
        .nationalId = "90022888157999",
        .nights = 2,
        .checkIn = {
            .day = 10,
            .month = 4,
            .year = 2024
        },
        .email = "dummy.khaled@gmail.com",
        .mobile = "01227333498"
    };

    Reservation arr[] = {test1, test2};
    sortrByDate(arr, 2);    // Will alter array given

    printf("Status of write function: %d", writeReservations("./reservations.txt", arr, 2));  // Status of write function: 1
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
