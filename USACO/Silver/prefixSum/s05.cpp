#include <iostream>
#include <vector>
using namespace std;

int main(){
    // freopen("homework.in", "r", stdin);
    // freopen("homework.out", "w", stdout);
    int n, num;
    long long sums[100003]= {}, arr[100003] = {}, mins[100003] = {};
    vector<int> out = {};
    cin >> n;
    
    sums[0] = 0;
    for(int idx = 1; idx <= n; idx++){
        cin >> num;
        arr[idx] = num;
        sums[idx] = sums[idx-1] + num;
    }
    
    int curMin = arr[n];
    mins[0] = curMin;
    for(int idx = n-1; idx >0; idx--){
        if(arr[idx] < curMin){
            curMin = arr[idx];
        }
        mins[idx] = curMin;
    }

    double avg, max = 0, total;
    for(int k = 1; k <= n-2; k++){
        // cout << mins[k+1] << '\n';
        total = sums[n]-sums[k]-mins[k+1];
        avg = (double)(total)/(n-k-1);
        if(max < avg){
            max = avg;
            out.clear();
            out.push_back(k);
        } else if(max == avg){
            out.push_back(k);
        }
        // cout << avg << '\n';
    }

    for(int idx = 0; idx < out.size(); idx++){
        cout << out[idx] << '\n';
    }
    return 0;
}