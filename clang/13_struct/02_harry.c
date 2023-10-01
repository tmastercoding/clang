#include <stdio.h>

char copy_str(char *dest, const char *src);

struct Books {
    // name
    char name[30];
    
    // author
    char auth[30];
    
    // publisher
    char publ[30];

    // borrowed
    int borrowed;

};

int main(){
    struct Books Harry_Potter;

    copy_str(Harry_Potter.name, "Harry Potter");
    copy_str(Harry_Potter.auth, "J.K. Rolling");
    copy_str(Harry_Potter.publ, "Scholastic");
    Harry_Potter.borrowed = 0;

    printf("Book name: %s \n", Harry_Potter.name);
    printf("Author name: %s \n", Harry_Potter.auth);
    printf("Publisher name: %s \n", Harry_Potter.publ);

    return 0;
}

char copy_str(char *dest, const char *src){
    while( *src ){
        *dest = *src;
        src++;
        dest++;
    }

    *dest = '\0';

    return 1;
}