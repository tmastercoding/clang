// 퇴사 14501
#include <iostream>
using namespace std;

int n;
// arr contains days 
int meet[20][2], arr[20] = {0,};
int maxPrice = 0, price;
// i = index of arr
void f(int i){
    int start = 0;
    if(i != 0){
        start = arr[i-1];
        start += meet[start][0];
    }
    bool hasFound = 0;
    // loop through days
    for(int d = start; d < n; d++){
        if(d + meet[d][0] > n){
            continue;
        }
        arr[i] = d;
        hasFound = true;
        f(i+1);
    }
    if(!hasFound){
        price = 0;
        for(int j = 0; j < i; j++){
            price += meet[arr[j]][1];
        }
        if (price > maxPrice){
            maxPrice = price;
        }
        return;
    }
}


int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin>> meet[i][0] >> meet[i][1];
    }
    f(0);
    cout << maxPrice << '\n';
    return 0;
}
