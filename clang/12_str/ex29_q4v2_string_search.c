#include <stdio.h>

#define FALSE 0
#define TRUE 1

int len(char *str);
int search(char *keyword, char *source, char *pos_arr);

int main(){
    char keyword[] = {"age"};
    char source[100] = {"apple agatha age arnold age"};
    char pos_arr;

    // printf("%d\n", len(keyword));
    // comp("age", "age");
    // int result;
    // result = search( keyword, source );

    // printf("%d\n", result);

    printf("source len: %d\n", len(source));
    printf("keyword len: %d\n", len(keyword));
    search(keyword,source);


    return 0;
}

int len(char *str){
    int count = 0;
    
    while(*str!='\0'){
        count++;
        str++;
    }

    return count+1;
}

int search(char *keyword, char *source) {

    int flag = FALSE;
    int source_len = len(source);
    printf("source len: %d\n", source_len);

    if( len(keyword) > source_len ){
        return 0;
    }

    for(int jdx = 0; jdx < source_len; jdx++, source++) {
        flag=TRUE;

        // printf( "== [  src Char : %d - %c ] ==\n ", jdx, *source);

        // inner :
        for( int idx = 0; idx < len(keyword)-1; idx++){
            // printf("= -> *keyword = [%c], *source = [%c], idx = [%d]\n", *(keyword+idx), *(source+idx), idx);
            if ( *(keyword+idx) != *(source + idx) ){
                // printf("= !! it will break\n");
                flag= FALSE;
                // return 0;
                break;
            }
        }
        if (flag==TRUE){
            printf("== [ POS ] : %d ==\n", jdx);
            break;
        }
    }

    return 1;
}