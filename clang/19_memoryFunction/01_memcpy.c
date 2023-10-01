#include <stdio.h>
#include <string.h>

int main(){
    char str[50] = "I love Chewing C hahahah";
    char str2[50];
    char str3[50];
    
    memcpy(str2, str, 5); 
    // where to, string, length of string 
    memcpy(str3, "hello", 6);

    printf("%s\n %s\n %s\n", str, str2, str3);

    return 0;
}