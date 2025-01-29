#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
 
vector<long long> AB, CD;
map<long long, long long> ABrepeat, CDrepeat;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    long long A[4000], B[4000], C[4000], D[4000], cnt = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    // sort(A, A+n);
    // sort(B, B+n);
    // sort(C, C+n);
    // sort(D, D+n);

    long long idx = 0;
    for(int a = 0; a < n; a++){
        for(int b = 0; b < n; b++){
            AB.push_back(A[a]+B[b]);
        }
    }

    idx = 0;
    for(int c = 0; c < n; c++){
        for(int d = 0; d < n; d++){
            CD.push_back(C[c]+D[d]);
        }
    }
    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());
    
    for(int idx = 0; idx < n*n; idx++){
        if(ABrepeat.find(AB[idx]) != ABrepeat.end()){
            ABrepeat[AB[idx]]++;
        } else{
            ABrepeat.insert({AB[idx], 1});
        }
    }

    for(int idx = 0; idx < n*n; idx++){
        if(CDrepeat.find(CD[idx]) != CDrepeat.end()){
            CDrepeat[CD[idx]]++;
        } else{
            CDrepeat.insert({CD[idx], 1});
        }
    }

    long long jdx = 1, prev = AB[0];
    for(int idx = 1; idx < n*n; idx++){
        if(AB[jdx] == prev){
            AB.erase(AB.begin()+jdx);
        } else{
            prev = AB[jdx];
            jdx++;
        }
    }

    // for(map<long long, long long>:: iterator it = ABrepeat.begin(); it != ABrepeat.end(); it++){
    //     cout << it->first << ' ' << it->second << '\n';
    // }

    jdx = 1, prev = CD[0];
    for(int idx = 1; idx < n*n; idx++){
        if(CD[jdx] == prev){
            CD.erase(CD.begin()+jdx);
        } else{
            prev = CD[jdx];
            jdx++;
        }
    }

    for(int ab = 0; ab < AB.size(); ab++){
        long long lo = 0, hi = CD.size(), mid;
        while(lo < hi){
            mid = (lo+hi)/2;
            if(CD[mid] < -AB[ab]){
                lo = mid+1;
            } else{
                hi = mid;
            }
        }

        // cout << CD[lo] << ' ' << AB[ab] << '\n';
        if(CD[lo] + AB[ab] == 0){
            // cout << ABrepeat[AB[ab]] << ' ' << CDrepeat[CD[lo]] << "\n";
            cnt+= ABrepeat[AB[ab]] * CDrepeat[CD[lo]];
        }
        // if(lo+1 < n){
        //     if(CD[lo+1] + AB[ab] == 0) cnt++;
        // }
    }
    cout << cnt << '\n';
    return 0;
}