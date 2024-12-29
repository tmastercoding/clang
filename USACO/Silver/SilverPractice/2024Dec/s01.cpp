#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long n, t;
    cin >> t;


    for(int i = 0; i < t; i++){
        vector<long long> v;
        long long e = 0, cake, sum = 0, tot = 0, minSum;
        cin >> n;
        for(int idx = 0; idx < n; idx++){
            cin >> cake;
            if(idx <= n/2){
                sum += cake;
            }
            tot += cake;
            v.push_back(cake);
        }
        minSum = sum;
        for(int idx = 0; idx <n/2-1; idx++){
            sum -= v[idx];
            sum += v[idx+n/2+1];
            // cout << sum << '\n';
            if(sum < minSum){
                minSum = sum;
            }
        }
        // int turn = 0;
        // while(v.size() > 1){
        //     if(!(turn & 1)){
        //         v[(int)(v.size())/2-1] += v[(int)(v.size())/2];
        //         v.erase(v.begin()+(int)(v.size())/2);
        //     } else{
        //         if(v[0] > *(v.end()-1)){
        //             e += v[0];
        //             v.erase(v.begin());
        //         } else{
        //             e += *(v.end()-1);
        //             v.erase(v.end()-1);
        //         }
        //     }
        //     turn++;
        // }

        cout << minSum << ' ' << tot-minSum << '\n';
    }
    
    return 0;
}