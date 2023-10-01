#include <stdio.h>

#define square( x ) ( ( x ) * ( x ) )
#define RADTODEG( x ) ( ( x ) * 57.295 )
#define PRINT_VARIABLE_NAME(var) printf( #var "\n" );
#define AddName(x, y) x##y

int main(int argc, char **argv){
    printf("square(3) : %d \n", square( 3 + 1 ));
    printf("5 rad is : %fdegrees\n", 1 / RADTODEG(5));

    int asdfapsdjfas;

    PRINT_VARIABLE_NAME(123456);

    int AddName( a, b ); 
    ab = 3;
    printf("%d \n", ab);

    return 0;
}