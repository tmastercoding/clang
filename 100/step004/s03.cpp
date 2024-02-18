#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;

void c_ver();
void cpp_ver();

int main(){
    // c_ver();
    cpp_ver();
    return 0;
}

void cpp_ver(){
    // declare variables
    int size = 0;
    int max, min, temp;
    int idx = 0;

    // input for size
    cin >> size;

    // restrictions for input

    // loop for size amount
    while(idx < size){
        // input temp
        cin >> temp;

        // assign temp to var
        if(!idx){
            max = temp;
            min = temp;
        } else {
            if(temp > max){
                max = temp;
            } else if(temp < min){
                min = temp;
            }
        }
        idx++;
    }

    // output
    cout << min << ' ' << max << endl;
}

void c_ver(){
    // input size
    int size = 0;
    int max;
    int min;
    int temp;
    scanf("%d", &size);

    // malloc numbers
    int* numbers = (int* )malloc(size * sizeof(int));

    // input numbers
    int idx = 0;
    while(idx < size){
        scanf("%d", &temp);
        if(!idx){
            min = temp;
            max = temp;
        } else {
            if(temp < min){
                min = temp;
            }
            if (temp > max){
                max = temp;
            }
        }
        numbers[idx++] = temp;
    }

    // // get min and max
    // idx = 1;
    // max = numbers[0];
    // min = numbers[0];
    // while(idx < size){
    //     // if num is smaller than min
    //     if(numbers[idx] < min){
    //         min = numbers[idx];
    //     }
    //     // if num is greater than max
    //     if(numbers[idx] > max) {
    //         max = numbers[idx];
    //     }
    //     idx++;
    // }

    printf("%d %d\n", min, max);
}