#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int roundt(int num, int p){
    double temp = (double)num/pow(10, p); 
    return round(temp) * pow(10, p);
}

int chainRound(int num, int p){
    for(int power = 1; power <=p; power++){
        num = roundt(num, power);
    }
    return num;
}

bool comp(pair<int, int> pre, pair<int, int> post){
    if(pre.second < post.second){
        return true;
    }
    return false;
}

int main(){
    int t = 0;
    cin >> t;
    pair<int, int> arr[100000];
    int temp;
    for(int i = 0; i < t; i++){
        cin >> temp;
        arr[i] = {temp, i};
    }
    sort(arr, arr+t);
    
    int to = arr[t-1].first, cnt = 0;
    int idx = 0;
    for(int test = 1; test <= to; test++){
        int p = to_string(test).size();
        if(roundt(test, p) != chainRound(test, p)){
            cnt++;
        }
        // cout << arr[idx].first << '\n';
        if(test == arr[idx].first){
            arr[idx++].first = cnt;
        }
    }
    sort(arr, arr+t, comp);
    for(int i = 0; i < t; i++){
        cout << arr[i].first << '\n';
    }

    return 0;
}