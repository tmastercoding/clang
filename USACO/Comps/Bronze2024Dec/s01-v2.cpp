#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int round(int num, int p){
    string s =  to_string(num);
    int x;
    int cnt = 0;
    for(int idx = s.size()-1; idx > -1; idx--){
        cnt++;
        if(cnt == p){
            x = s[idx]-'0';
        }
    }
    
    if(x>= 5){
        num += pow(10, p);
    }
    s = to_string(num);

    cnt = 0;
    for(int idx = s.size()-1; idx > -1; idx--){
        cnt++;
        s[idx] = '0';
        if(cnt == p){
            break;
        }
    }

    num = stoi(s);
    // cout << num << '\n';
    return num;
}

int chainRound(int num, int p){
    for(int power = 1; power <=p; power++){
        num = round(num, power);
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
        if(round(test, p) != chainRound(test, p)){
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