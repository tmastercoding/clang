// Monthly Expense 6236
#include <iostream>
using namespace std;

int main(){
    int n, m, moneys[100000];
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> moneys[i];
    }

    long long lo = 0, hi = 1000000000, mid, cnt, sum;
    while(lo < hi){
        mid = (lo+hi)/2;
        cnt = 1, sum = 0;
        for(int i = 0; i < cnt; i)
    }
    return 0;
}