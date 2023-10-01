#include <iostream>
#include <stdio.h>
using namespace std;

void c_ver(){
    int a, b;

    printf("Input a: \n");
    scanf("%d", &a);
    fflush(stdin);

    printf("Input b: \n");
    scanf("%d", &b);
    fflush(stdin);

    printf("Result: %d\n", a+b);
}

void cpp_ver(){
    int a;
    int b;

    cout << "Input A: ";
    cin >> a;

    cout << "Input B: ";
    cin >> b;

    cout << "Result: " << a+b << endl; 
}

int c_ver_input_int(){
    int num = 0;
    printf( "Input number: \n");

    char buffer[20];
    char *p_buffer = buffer;
    char ch;
    int flag = 0;
    int length = 0;
    
    // input
    while( ( ch = getchar() ) != '\n' ){
        if( '9' < ch && ch < '0'){
            flag = 1;
            break;
        } else {
            *(p_buffer++) = ch;
            length++;
        }
    } 

    if(flag){
        printf("Input only number~~~\n");
    } else {

        // convert to int
        for(int idx = length; idx > 0; idx--){

            int cur_digit = buffer[ length - idx ] - '0';

            int pow = 1;
            for(int jdx = 0; jdx < idx-1; jdx++, pow*=10);

            num += (cur_digit)*(pow);
        }
    }
    

    return num;
}

void c_ver_using_getchar() {
    int a, b;
    a = c_ver_input_int();
    b = c_ver_input_int();

    printf("Result: %d\n", a+b);
}


int main(){
    // c_ver();
    // cpp_ver();

    c_ver_using_getchar();
    return 0;
}