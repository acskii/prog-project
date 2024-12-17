# Programming-1 Repo
I will post my contributions here related to the Final Project for Programming-1 C course
:)

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
## Resources
- Check out this [video](https://www.youtube.com/watch?v=idXIb84gsqU) for header files explanation
- Second answer to this [question](https://stackoverflow.com/questions/20120833/how-do-i-refer-to-a-typedef-in-a-header-file) helped make the `typedef struct`s in type.h
- Check out this [article](https://www.geeksforgeeks.org/header-files-in-c-cpp-and-its-uses/) also for header files 
