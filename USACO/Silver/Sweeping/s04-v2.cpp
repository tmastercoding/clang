#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    long long n, q, start, end, height, from, to;
    cin >> n >> q;
    vector<long long> logs[100001], log, questions[100001], question;
    long long translate[100001], paths[100001];

    for(long long idx = 0; idx < n; idx++){
        cin >> start >> end >> height;
        log.clear();
        log.push_back(start);
        log.push_back(end);
        log.push_back(height);
        log.push_back(idx+1);
        logs[idx] = log;
    }

    for(long long idx = 0; idx < q; idx++){
        cin >> from >> to;
        question.clear();
        question.push_back(from);
        question.push_back(to);
        questions[idx] = question;
    }
    sort(logs, logs+n);
    for(long long idx = 0; idx < n; idx++){
        translate[logs[idx][3]] = idx+1;
    }

    long long cnt = 0, max = 0;
    paths[0] = 0;
    for(long long idx = 0; idx < n; idx++){
        if(max < logs[idx][0]){
            cnt++;
        }
        if(max < logs[idx][1]){
            max = logs[idx][1];
        }
        paths[idx] = cnt;
    }
    // for(long long idx = 0; idx < n; idx++){
    //     cout << paths[idx] << ' ';
    // }
    // cout << '\n';
   

    for(long long idx = 0; idx < q; idx++){
        from = translate[questions[idx][0]];
        to = translate[questions[idx][1]];
        // if(from > to){
        //     long long temp = from;
        //     from = to;
        //     to = temp;
        // }
        if( paths[from-1] ==paths[to-1] ){
            cout << "1\n";
        } else{
            cout << "0\n";
        }
    }
    return 0;
}