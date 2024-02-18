#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int num = 10;

    char output_format[] = "%d";

    char add_format[] = " %d";

    char* total_format;

    int size_output_format = sizeof( output_format ) / sizeof(char);
    int size_add_format = sizeof( output_format ) / sizeof(char);

    int total_format_size = size_output_format + size_add_format;

    total_format = (char *)malloc(total_format_size);

    strcpy(total_format, output_format);
    strcpy(total_format+size_output_format-1, add_format);

    printf("%lu\n", sizeof(total_format));
    printf("%d\n", total_format_size);
    printf( "%s\n", total_format );

    int list[2];
    scanf("%d %d", &list[0], &list[1]);
    for(int item: list){
        printf("%d ", item);
    }
    // printf( output_format, size-1 );
    printf( "\n" );

    return 0;
}