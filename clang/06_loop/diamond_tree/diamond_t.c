#include <stdio.h>

int main()  {
    int size = 5;
    int col_size;
    // int rate = 0;
    int point;

    scanf( "%d", &size );
    col_size = size * 2 - 1;

    // assigns 2 variables row and rate. 
    /// Row is normal pyramid (starts from -4), 
    // rate is reverse (0).
    for( int row = size-1, rate = 0; row > -1 ; row--, rate++  )   {      
        
        // Ternary; point is. rate if rate is greater than half of size. 
        // Else point is row
        // Example: if rate = 0, (when size = 5) size/2 = 2.5
        // 0 is not greater than 2.5. So point is row.
        point = ( rate > size / 2 ) ? rate : row; 

        // point = row;

        // if( rate > size / 2 )   {
        //     printf( "rate : %d\n", rate );
        //     point = rate;
        // }

        for( int col = 0; col < col_size  ; col++ )   {
            
            // 
            if( ( point > col ) || ( ( col_size - point - 1 ) < col ) )    {
                printf( "  " );
            } else {
                printf( "* " );
            }
        }
        printf( "\n" );
    }

    return 0;
}