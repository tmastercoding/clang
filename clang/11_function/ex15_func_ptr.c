#include <stdio.h>

int max(int a, int b);
int min( int a, int b );

int main(){
    int a, b;
    int (*pfun)(int, int);
    pfun = max;
    
    scanf("%d %d", &a, &b);

    int flag = 1;
    int select_number = 0;

    while( flag ) {
        printf("=== select one ===\n");
        printf("=== 0 : max ===\n");
        printf("=== 1 : min ===\n");
        printf("=== other exit ===\n");
        scanf("%d", &select_number);
        switch ( select_number )
        {
            case 0:
                pfun = max;
                /* code */
                printf("%d\n", pfun(a, b ));
                break;

            case 1:
                pfun = min;
                printf("%d\n", pfun(a, b ));
                /* code */
                break;
            
            default:
                flag = 0;
                break;
        }


    }

    printf("max(a,b) : %d \n", max(a, b));
    printf("pfun(a, b): %d \n", pfun(a,b));

    return 0;
}

int max(int a, int b){
    if(a > b){
        return a;
    }

    return b;
}

int min( int a, int b ) { return  (a < b)? a: b; }