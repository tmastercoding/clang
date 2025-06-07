// Martian DNA 15862
#include <iostream>
#include <map>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n, k, r;
    int arr[200000], cnts[200000] = {}, reqs[200000] = {};
    map<int, int> m;
    cin >> n >> k >> r;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int b, q;
    for(int i = 0; i < r; i++){
        cin >> b >> q;
        reqs[b] = q;
        m.insert({b, q});
    }
    
    int lo = 0, hi = -1, cnt = 0, min = 200001;
    // init
    while(true){
        hi++;
        if(hi >= n) break;
        cnt++;
        cnts[arr[hi]]++;
        if(m.find(arr[hi])!= m.end()){
            m[arr[hi]]--;
            if(m[arr[hi]] <= 0){
                m.erase(arr[hi]);
            }
        }
        if(m.size() == 0){
            min = cnt;
            break;
        }
    }
    if(min != 200001){
        while(true){
            if(!m.size()){
                if(cnt < min) min = cnt;
                cnts[arr[lo]]--;
                if(reqs[arr[lo]] > cnts[arr[lo]]){
                    m.insert({arr[lo], 1});
                }
                lo++;
                cnt--;
            } else{
                hi++;
                if(hi >= n) break;
                cnt++;
                cnts[arr[hi]]++;
                if(m.find(arr[hi])!= m.end()){
                    m[arr[hi]]--;
                    if(m[arr[hi]] <= 0){
                        m.erase(arr[hi]);
                    }
                }
            }
        }
        cout << min << '\n';
    } else{
        cout << "impossible\n";
    }
    
    return 0;
}