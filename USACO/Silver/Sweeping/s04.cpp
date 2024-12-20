#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    long long n, q, start, end, height, from, to;
    cin >> n >> q;
    vector<long long> logs[100001], log, questions[100001], question, paths;
    long long translate[100001];

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

    for(long long idx = 1; idx < n; idx++){
        if(logs[idx-1][1] < logs[idx][0]){
            paths.push_back(idx);
        }
    }
    paths.push_back(n);

    for(long long idx = 0; idx < q; idx++){
        from = translate[questions[idx][0]];
        to = translate[questions[idx][1]];
        if(from > to){
            long long temp = from;
            from = to;
            to = temp;
        }
        for(long long jdx = 0; jdx < paths.size(); jdx++){
            if( to <= paths[jdx]){
                if(jdx > 0){
                    if(from > paths[jdx-1]){
                        cout << "1\n";
                    } else{
                        cout << "0\n";
                    }
                } else{
                    cout << "1\n";
                }
                break;
            }
        }
    }
    return 0;
}