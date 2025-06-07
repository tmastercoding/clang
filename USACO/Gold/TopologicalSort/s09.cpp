#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <vector>
using namespace std;

set<int> dadj[26], adj[26];
int visit[26] = {};
void dfs(int cur){
    visit[cur] = 1;
    for(auto nxt : dadj[cur]){
        if(!visit[nxt]){
            dfs(nxt);
        }
    }
}

int main(){
    int in[26] = {}, n;
    int arr[100][10];
    int appear[26] = {};
    
    cin >> n;
    string buffer;
    for(int i = 0; i < n; i++){
        cin >> buffer;
        int j = 0;
        for(char ch: buffer){
            arr[i][j++] = ch-'a';
            appear[ch-'a'] = 1;
        }
        for(; j < 10; j++){
            arr[i][j] = -1;
        }
    }  
    bool cflag = false;

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int ch = 0; ch < 10; ch++){
                if(arr[i][ch] == -1){
                    break;
                }
                if(arr[j][ch] == -1){
                    cflag = true;
                    break;
                }
                if(arr[i][ch] != arr[j][ch]){
                    adj[arr[i][ch]].insert(arr[j][ch]);
                    dadj[arr[i][ch]].insert(arr[j][ch]);
                    dadj[arr[j][ch]].insert(arr[i][ch]);
                    break;
                }
            }
        }
    }

    // for(int i = 0; i < 26; i++){
    //     if(!appear[i]) continue;
    //     cout << (char)(i+'a') << ':' << '\n';
    //     for(auto nxt : adj[i]){
    //         cout << (char)(nxt+'a') << ' ';
    //     }
    //     cout << '\n';
    // }

    bool whole = true;
    int cnt = 0;
    for(int i = 0; i < 26; i++){
        if(!appear[i]) continue;
        if(!visit[i]){
            if(cnt > 0){
                whole = false;
                break;
            }
            dfs(i);
            cnt++;
        }
    }
    // cout << whole << '\n';

    
    for(int i = 0; i < 26; i++){
        for(auto nxt: adj[i]){
            in[nxt]++;
        }
    }
    queue<int> q;
    vector<char> out;
    for(int i = 0; i < 26; i++){
        if(!in[i] && appear[i]) q.push(i);
    }

    
    while(!q.empty()){
        if(q.size()> 1) whole = false;
        int cur = q.front();
        out.push_back(cur+'a');
        q.pop();
        
        for(auto nxt: adj[cur]){
            in[nxt]--;
            if(!in[nxt]) q.push(nxt);
        }
    }
    
    bool cycle = false;
    for(int i = 0; i < 26; i++){
        if(in[i] && appear[i]) cycle = true;
    }
    int c = 0;
    for(int i = 0; i < 26; i++){
        if(appear[i]) c++;
    }
    
    for(char ch: out){
        appear[ch-'a'] = 0;
    }
    bool flag = true;
    for(int i = 0; i < 26; i++){
        if(appear[i]) flag = false;
    }
    if(out.size() != c || !flag) whole = false;

    if(cycle || cflag){
        cout << "!\n";
    } else if(!whole){
        cout << "?\n";
    } else{
        for(char ch: out){
            cout << ch;
        }
        cout << '\n';
    }
    return 0;
}