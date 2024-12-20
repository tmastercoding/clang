// 선 긋기 2170
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    // long long int lines[1000000][2];
    vector<pair<long long , long long>> lines;
    pair<long long , long long> line;
    for(int idx = 0; idx < n; idx++){
        cin >> line.first >> line.second;
        lines.push_back(line);
    }
    sort(lines.begin(), lines.end());
    // for(int idx = 0; idx < n; idx++){
    //     cout << lines[idx].first << ' ' << lines[idx].second << '\n';
    // }
    int max = lines[0].second;
    int length = lines[0].second - lines[0].first;

    for(int idx = 1; idx < n; idx++){
        //  overlap
        if(max >= lines[idx].first){
            if(lines[idx].second > max){
                length += lines[idx].second - max;
            }
        } else{
            length += lines[idx].second-lines[idx].first;
        }
        if(max < lines[idx].second){
            max = lines[idx].second;
        }


    }
    cout << length << '\n';
    return 0;
}