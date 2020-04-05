#include <stdio.h>
#include <string.h>

struct packed_struct {
    unsigned int f1:1;
    unsigned int f2:1;
    unsigned int f3:1;
    unsigned int f4:1;
    unsigned int type:4;
    unsigned int my_int:9;
} pack;

int main( ) {

    struct packed_struct pck;

    pck.f1 = 1;

    printf( "f1: %d\n", pck.f1);

    return 0;
}
