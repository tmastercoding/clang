#include <iostream>
#include <algorithm>
using namespace std;

pair<long long, long long> rides[300000], ride;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    long long n, m;
    cin >> n >> m;
    long long start, end, size = 0;

    for(int idx = 0; idx < n; idx++){
        cin >> start >> end;
        if(start > end){
            ride.first = end;
            ride.second = start;
        }
        rides[size++] = ride;
    }
    sort(rides, rides+size);

    long long length = 0, max = -1;
    for(int idx = 0; idx < size; idx++){
        if(max != -1){
            if(max > rides[idx].first){
                if(max < rides[idx].second){
                    length+= rides[idx].second - max;

                }
            } else{
                length += rides[idx].second - rides[idx].first;
            }
        } else{
            length += rides[idx].second - rides[idx].first;
        }

        if(rides[idx].second > max){
            max = rides[idx].second;
        }
        // cout << length << '\n';
    }
    cout << length*2+m << '\n';
    return 0;
}