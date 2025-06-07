// 카드 게임 16566
#include <iostream>
using namespace std;

int p[4000001] = {};

int Find(int x){
    if(x == p[x]) return x;
    return p[x] = Find(p[x]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);

    if(a == b) return;
    if(a > b) swap(a, b);
    p[a] = b;
}

int played[10000] = {}, deck[4000000] = {};
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0; i < m; i++){
        cin >> deck[i];
        p[deck[i]] = deck[i];
    }

    for(int i = 0; i < k; i++) cin >> played[i];
    
    for(int i = 1; i < n; i++){
        if(!p[i]) p[i] = i+1;
    }
    
    for(int i = 0; i < k; i++){
        int play = Find(played[i]+1);
        cout << play << '\n';
        Union(play, play+1);
    }
    return 0;
}