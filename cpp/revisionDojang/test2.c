#include <stdio.h>
#include <string.h>

int otai_len( char* text ) {
    int count = 0;
    while( *(text++) != '\0' ) {
        count++;
    }
    return count;
}

int main() {
    // char a[12] = "ILoveCoding";
    char a[] = "ILoke\0oding";
    char* p = a+3;

    strcpy(a+3, "ke");

    int[] nums = { 0, 1 };

    // 0000000000000000000000 000000000000000001

    printf("%s %d\n", a+3, (int)strlen(a+3));
    printf("%s %d\n", a+6, (int)strlen(a+6));
    printf("%s %d\n", a+6, (int)otai_len(a+6));


    return 0;
}
