#include <iostream>
#include <vector>
using namespace std;

int arr[1000001], up[1000001] = {}, depths[1000001], in[1000001], out[1000001], checks[1000001] = {};
vector<int> tree[1000001];
int main(){
    int n, num;
    cin >> n;
    for(int i = 0; i <= n; i++){
        arr[i] = i;
    }

    depths[0] = 1;
    for(int i = 0; i < n; i++){
        cin >> num;
        tree[num].push_back(i+1);
        depths[i+1] = depths[num]+1;
        up[i+1] = num;
    }

    int m = 0;
    for(int i = 0; i <= n; i++){
        if(tree[i].empty()){
            m++;
        }
    }
    for(int i = 0; i < m; i++){
        cin >> in[i];
    }
    
    for(int i = m-1; i > -1; i--){
        int temp = in[i], cnt = 0;

        while(true){
            checks[temp] = 1;
            cnt++;
            temp = up[temp];
            if(checks[temp]) break;
        }
        // cout << in[i] << ' ' << depths[in[i]] << ' ' << cnt << '\n';
        out[i] = depths[in[i]]-cnt;
    }

    for(int i = 0; i < m; i++){
        cout << out[i] << '\n';
    }
    return 0;
}