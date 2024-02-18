#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

/**
 * @date 23.01.14
 * @author Tay Oh
 * @details code getting length, a list of integers and a
 *          number, returning how many of that number is in
 *          the list.
*/

int cpp_ver();
int c_ver();
void c_input(int* var, int startRange, int endRange);
void cpp_input(int* var, int startRange, int endRange);

int main(){
    // c_ver();
    cpp_ver();
    return 0;
}

// to check correct input
void c_input(int* var, int startRange, int endRange){
    while(1){
        // get input
        scanf("%d", var);
        fflush(stdin);

        // if in range
        if((startRange<=(*var) )&& ((*var)<=endRange)){
            break;
        }

        // try again message
        printf("Please input an integer betweeen(inlcuding) %d and %d.\n", startRange, endRange);
    }
}

// to check correct input
void cpp_input(int* var, int startRange, int endRange){
    while(1){
        // get input
        cin >> *var;

        // if in range
        if((startRange<=(*var) )&& ((*var)<=endRange)){
            break;
        }
        // try again message
        printf("Please input an integer betweeen(inlcuding) %d and %d.\n", startRange, endRange);
    }
}



int c_ver(){
    // input for length
    int length, number;
    c_input(&length, 1, 100);


    // malloc numberArr
    int* numberArr = (int *)malloc(length*sizeof(int));
    int idx = 0;
    // get input into numberArr
    while(idx < length-1){
        scanf("%d ", &numberArr[idx]);
        idx++;
    }
    scanf("%d", &numberArr[idx]);
    fflush(stdin);

    // input for number
    c_input(&number, -100, 100);

    
    int count = 0;
    // loop numberArr
    for(int idx = 0; idx<length; idx++){
        // increase count if match
        if(number == numberArr[idx]) count++;
    }

    printf("%d\n", count);


    // int *arr = (int*)malloc(sizeof(int) * length);
    // char* p = strtok(buffer, sep);
    // int idx = 0; 

    // while(p != 0){
    //     arr[idx++] = stoi(p);
    //     p = strtok(NULL, sep);
    // }
    
    // scanf("%d", &number);
    // fflush(stdin);
    // int count = 0;

    // for(int idx = 0; idx < length; idx++){
    //     if(arr[idx] == number){
    //         count++;
    //     }
    // }   

    // printf("%d\n", count);
    
    
    // char format[] = "%d";
    // char add_format[] = {' ', '%', 'd'};

    // int size_format = sizeof(format);
    // int size_add_format = sizeof(add_format);
    // int size_total_format = size_format + ((length-1)*size_add_format);

    // char* total_format = (char *)malloc(size_total_format);
    // strcpy(total_format, format);

    // int pos = size_format-1;
    // int count = 1;
    // while(count != length){
    //     strcpy(total_format+pos, add_format);
    //     pos += size_add_format;
    //     count++;
    // }
    return 0;
}

int cpp_ver(){
    // input length
    int length, number;
    cpp_input(&length, 1, 100);

    // vector for numbers
    vector<int> numberV;

    int idx = 0;
    int temp = 0;
    // input into numberV
    while(idx < length){
        cin >> temp;
        numberV.push_back(temp);
        idx++;  
    }

    // input number
    cpp_input(&number, -100, 100);

    int count = 0;
    // iter numberV
    vector<int>::iterator iter = numberV.begin();
    for(; iter != numberV.end(); iter++){
        // if match increase count
        if(*iter == number) count++;
    }
    cout << count << endl;

    return 0;

    // string buffer;
    // cin >> buffer;
    // cout << buffer << endl;

    // int sizeBuffer = buffer.length()+1;
    // char sep[] = " ";

    // char* cstr = new char[ sizeBuffer ];
    // strcpy(cstr, buffer.c_str());

    // char* p = strtok(cstr, sep);
    // int idx = 0;
    // while( p != 0){
    //     numberV.push_back(stoi(p));
    //     cout << idx << endl;
    //     idx++;
    //     p = strtok( NULL, sep );
    // }

    // auto print = [](const int &n) {cout << n << ' ';};
    // for_each(numberV.begin(), numberV.end(), print );
    // cout << endl;
}