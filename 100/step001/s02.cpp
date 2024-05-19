#include <iostream>
#include <stdio.h>
using namespace std;

void c_ver(){
    // declare two integers
    int a, b;

    // get input using scanf
    printf("Input a: \n");
    scanf("%d", &a);
    // fflush to flush trash input
    fflush(stdin);

    // repeat
    printf("Input b: \n");
    scanf("%d", &b);
    fflush(stdin);

    // print the sum
    printf("Result: %d\n", a+b);
}

void cpp_ver(){
    // declares two integers
    int a;
    int b;

    // gets input using cin >>
    cout << "Input A: ";
    cin >> a;

    cout << "Input B: ";
    cin >> b;

    // print the sum
    cout << "Result: " << a+b << endl; 
}

// function for int input
int c_ver_input_int(){
    // declare int
    int num = 0;
    printf( "Input number: \n");

    // create buffer array size 20
    char buffer[20];
    // ptr to buffer
    char *p_buffer = buffer;
    char ch;
    // isNotNumber flag
    int flag = 0;
    int length = 0;
    
    // input
    // while getchar() isn't a new line
    while( ( ch = getchar() ) != '\n' ){
        // if char is not a number
        if( '9' < ch && ch < '0'){
            // flag True
            flag = 1;
            break;
        } else {
            // add ch to buffer
            *(p_buffer++) = ch;
            // increase length
            length++;
        }
    } 

    // if isNotNumber
    if(flag){
        // display error
        printf("Input only number~~~\n");
    } else {

        // convert to int
        // loop buffer from end to start
        for(int idx = length; idx > 0; idx--){
            // get digit in numbers by - '0'
            // char is a int ASCII
            int cur_digit = buffer[ length - idx ] - '0';

            int pow = 1;
            // multiply 10 to pow accrd to idx
            for(int jdx = 0; jdx < idx-1; jdx++, pow*=10);

            // add digit * pow to num
            num += (cur_digit)*(pow);   
        }
    }
    
    return num;
}

void c_ver_using_getchar() {
    // declare 2 int
    int a, b;
    // get input by func
    a = c_ver_input_int();
    b = c_ver_input_int();

    // get sum
    printf("Result: %d\n", a+b);
}


int main(){
    // c_ver();
    // cpp_ver();

    c_ver_using_getchar();
    return 0;
}