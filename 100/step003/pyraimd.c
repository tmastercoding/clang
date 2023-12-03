#include <stdio.h>

int main()  {
    int size;
    int col_size;

    scanf( "%d", &size );

    col_size = size * 2 - 1;

    for( int row = size-1; row > -1 ; row-- )   {
        for( int col = 0; col < col_size ; col++ )   {
            
            if( ( row > col ) || ( ( col_size - row - 1 ) < col ) )    {
                printf( "  " );
            } else {
                printf( "* " );
            }
        }
        printf( "\n" );
    }

    printf( "\nreverse\n" );
    // reverse
    for( int row = 0; row < size ; row++ )   {
        for( int col = 0; col < col_size ; col++ )   {
            
            if( ( row > col ) || ( ( col_size - row - 1 ) < col ) )    {
                printf( "  " );
            } else {
                printf( "* " );
            }
        }
        printf( "\n" );
    }

    return 0;
}