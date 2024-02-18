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
    // declare val
    int sizeBasket = 0;
    int noOfPut = 0;
    int idx, tempFrom, tempTill, tempBall = 0;

    // inpuit
    scanf("%d %d", &sizeBasket, &noOfPut);

    // malloc basket list
    int *baskets = (int *)malloc(sizeof(int) * sizeBasket);

    // loop for noOfPut
    while(idx < noOfPut+1){
        // input
        scanf("%d %d %d", &tempFrom, &tempTill, &tempBall);
        
        // assign val
        for (int jdx = tempFrom; jdx < tempTill+1; jdx++){
            baskets[jdx-1] = tempBall;
        }
        idx++;
    }

    // output
    for(int idx = 0; idx < sizeBasket; idx++){
        printf("%d ", baskets[idx]);
    }
    printf("\n");

    // free memory
    free(baskets);
}

void cpp_ver(){
    // declare var
    int sizeBasket = 0;
    int noOfPut = 0;
    int idx, tempFrom, tempTill, tempBall = 0;

    // input
    cin >> sizeBasket >> noOfPut;
    
    // declare and set map
    map<int, int> baskets;
    for(int key = 1; key < sizeBasket+1; key++){
        baskets.insert(pair<int, int>(key, 0));
    }

    // loop for noOfPut
    while(idx < noOfPut+1){
        // input
        cin >> tempFrom >> tempTill >> tempBall;
        // assign val
        for(int jdx = tempFrom; jdx < tempTill+1; jdx++){
            baskets[jdx] = tempBall;
        }
        idx++;
    }

    // ouput
    for( map<int, int>::iterator it = baskets.begin(); it!= baskets.end(); it++){
        cout << it->second << ' ';
    }

    cout << endl;
}