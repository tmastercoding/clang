#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> bpq, spq;
    int sin[10] = {}, bin[10] = {};
    vector<int> sadj[10], badj[10];
    int sout[10], bout[10];
    int k;
    cin >> k;
    char sign;
    for(int i = 1; i <= k; i++){
        cin >> sign; 
        if(sign == '<'){
            sin[i-1]++;
            sadj[i].push_back(i-1);
            bin[i]++;
            badj[i-1].push_back(i);
        } else{
            sin[i]++;
            sadj[i-1].push_back(i);
            bin[i-1]++;
            badj[i].push_back(i-1);
        }
    }

    for(int i = 0; i <= k; i++){
        if(!bin[i]) bpq.push(i);
        if(!sin[i]) spq.push(i);
    }

    int idx = 0;
    while(!bpq.empty()){
        int cur = bpq.top();
        bpq.pop();
        bout[idx++] = cur;
        for(int nxt: badj[cur]){
            bin[nxt]--;
            if(!bin[nxt]) bpq.push(nxt);
        }
    }
    idx = 0;
    while(!spq.empty()){
        int cur = spq.top();
        spq.pop();
        sout[idx++] = 9-cur;
        for(int nxt: sadj[cur]){
            sin[nxt]--;
            if(!sin[nxt]) spq.push(nxt);
        }
    }

    for(int i = 0; i <= k; i++){
        cout << sout[i];
    }
    cout << '\n';
    for(int i = 0; i <= k; i++){
        cout << bout[i];
    }
    cout << '\n';
    return 0;
}