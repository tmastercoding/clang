#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

void c_ver();
void cpp_ver();

int main(){
    // c_ver();
    cpp_ver();
    return 0;
}

void c_ver(){
    int divisor = 42;
    // array set to -1
    int buffer[10]= {-1,};
    int count = 0;
    int size = 0;
    int temp;

    // get input and divde
    while(1){
        if(count == 10){
            break;
        }
        scanf("%d", &temp);
        buffer[count] = temp%divisor;
        count++;
    }

    // loop through idx
    for(int idx = 0; idx < 10; idx++){
        // if term been cancelled
        if(buffer[idx] == -1){
            continue;
        }
        
        // loop starting after idx
        for(int jdx = idx+1; jdx < 10; jdx++){
            // if term been cancelled
            if(buffer[jdx] == -1){
                continue;
            }

            // if terms equal
            if(buffer[idx] == buffer[jdx]){
                // printf("%d == %d\n", buffer[idx], buffer[jdx]);
                // cancel
                buffer[jdx] = -1;
            }
        }
    }

    // add when term is not cancelled
    for(int idx = 0; idx < 10; idx++){
        if(buffer[idx] != -1){
            size++;
        }  
    }

    // print size
    printf("%d\n", size);    
}

void cpp_ver(){
    // no repeat vals in map
    map<int, bool> remainders;
    int temp;

    // input and insert
    for(int idx = 0; idx < 10; idx++){
        cin >> temp;
        remainders.insert(pair<int, bool>(temp%42, false));
    }

    // print size
    cout << remainders.size()<< endl;
}