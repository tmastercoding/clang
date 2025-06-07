#include <iostream>
#include <vector>
using namespace std;

int arr[1000001], up[1000001] = {}, sizes[1000001];
vector<int> tree[1000001];
int main(){
    int n, num;
    cin >> n;
    for(int i = 0; i <= n; i++){
        arr[i] = i;
    }

    for(int i = 0; i < n; i++){
        cin >> num;
        tree[num].push_back(i+1);
        up[i+1] = num;
    }
    int m = 0;
    for(int i = 0; i <= n; i++){
        sizes[i] = tree[i].size();
        if(tree[i].empty()){
            m++;
        }
    }

    for(int i = 0; i < m; i++){
        cin >> num;
        int temp = num, cnt = 0;
        bool needFrom = false;

        while(true){
            int prev = temp;
            temp = up[temp];
            if(sizes[temp] > 1 || needFrom){
                cnt++;
                needFrom = true;
            }
            if(sizes[prev] == 0){
                sizes[temp]--;
            }
            if(temp == 0){
                break;
            }
            // tree[temp].÷erase()
        }

        cout << cnt << "\n";
    }

    // cout << m << '\n';
    return 0;
}