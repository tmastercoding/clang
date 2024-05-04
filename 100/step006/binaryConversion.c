#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char* getBinary( int num);
char* getOctal(  int num);
char* getHexa(   int num);
// only works if base = power of 2
char* getNumSys(int num, int base);

int main(){
    printf("%s\n", getNumSys(32, 32));
    return 0;
}

char* getBinary(int num){
    // 5 = 101
    // 5 = 010
    // 7 = 111
    // 111 & 1
    // 0111 & 1111 = 0111 

    int temp = num;
    int count = 0;
    char buffer[100] = {'\0',};
    while(temp > 0){
        buffer[count++] = (temp & 1) + '0';
        temp >>= 1;
    }

    char* binary = (char* )malloc(sizeof(char) * count);
    for(int idx = 0; idx < count; idx++){
        binary[idx] = buffer[count-idx-1];
    }

    return binary;
}

char* getOctal(int num){
    const int size = 100;
    int count = size-1;
    char buffer[size] = {'\0', };
    char* octal;

    while(num > 0){
        buffer[count--] = (num & 7) + '0';
        num >>= 3;
    }

    octal = (char* )malloc(sizeof(char) * (size-count));
    // for(int idx = 0; count >= 0; idx++, count--){
    for(int idx = count+1; idx < size; idx++){
        // octal[idx] = buffer[count];
        octal[idx-count-1] = buffer[idx];
    }

    return octal;
}

// 16 
// 10000
// 01111

char* getHexa(int num){
    int count = 0;
    char buffer[100] = {'\0', };
    int temp = 0;
    char* hexa;

    while(num > 0){
        temp = num&15;
        buffer[count++] = temp + ((temp > 9)? 'a' - 10: '0');
        num >>= 4;
    }
    
    hexa = (char*)malloc(count*sizeof(char));
    for(int idx = count-1; idx > -1; idx--){
        hexa[count-idx-1] = buffer[idx];
    }

    return hexa;
}

char* getNumSys(int num, int base){
    int count = 0;
    char buffer[100] = {'\0', };
    int temp = 0;
    char* numSys;

    // switch( base ) {
    //     case 2:
    //         break;
    //     case 8:
    //         break;
    //     case 16:
    //         break;
    //     default:
    // }

    while(num > 0){
        temp = num&(base-1);
        buffer[count++] = temp+ ((temp>9)? 'a'-10: '0');
        num >>= (int)(log(base)/log(2));
    }

    numSys = (char*)malloc(count*sizeof(char));
    for(int idx = count-1; idx > -1; idx--){
        numSys[count-idx-1] = buffer[idx];
    }

    return numSys;
}