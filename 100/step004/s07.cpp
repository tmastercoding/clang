#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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
    int total = 5;
    int count = 0;
    // array set to 0
    int students[5] = {0,};

    // loop 3 times
    while (1) {
        if(count == 3){
            break;
        }
        // get input
        int temp;
        scanf("%d", &temp);

        // set temp th to 1
        students[temp-1] = 1;
        count++;
    }
    
    count = 0;
    // print idx with 1 as val
    while(1){
        if(count == 5){
            break;
        }
        if(!students[count]){
            printf("%d\n", count+1);
        }
        count++;
    }
}

void cpp_ver(){
    int size = 5;
    int count = 0;

    // map
    map<int, bool> students;
    // set to 0
    for(int idx = 0; idx < size; idx++){
        students.insert(pair<int, bool>(idx+1, false));
    }

    // get input
    while(1){
        if(count == 3){
            break;
        }
        int temp;
        cin >> temp;
        // set to true
        students[temp] = true;
        count++;
    }

    // loop map
    for(map<int, bool>::iterator it = students.begin(); it != students.end(); it++){
        // print the key which have 0
        if(!(it->second)){
            cout << it->first << endl;
        }
    }
}