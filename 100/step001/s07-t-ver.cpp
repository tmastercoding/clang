#include <stdio.h>
#include <stdlib.h>

void input( char* temp );
int length( char* temp );
void str_copy( char* src, char* dest );

int main() {

    char emootion[] = { '!', '!', '?' };

    char id[20] = { 0, };
    input( id );
    int len = length( id );
    int emotion_len = length( emootion );
    char* supprise_id = (char *)malloc( sizeof( char ) * (len + emotion_len ) );


    str_copy( id, supprise_id  );
    str_copy( emootion, supprise_id + len - 1  );

    *( supprise_id + len + emotion_len - 1) = '\0';

    printf( "%s\n", supprise_id );

    return 0;
}

void input( char *temp ) {
    const int size = 20;
    char buffer[size] = { 0, };
    char* pbuff = buffer;
    char ch;

    while( ( ch = getchar() ) != '\n' ) {
        *(pbuff++) = ch;
    }
    *pbuff = '\0';

    str_copy( buffer, temp );
}

int length( char* temp ) {
    int cnt = 0;

    while( *(temp++) != '\0' ) {
        cnt++;
    }

    return cnt+1;
}

void str_copy( char* src, char* dest ) {

    while( *src != '\0' ) {
        *dest = *src;
        dest++;
        src++;
    }
}
