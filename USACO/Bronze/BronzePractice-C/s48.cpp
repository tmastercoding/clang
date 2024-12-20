// Lonely Photo
#include <iostream>
#include <string>
using namespace std;

int main(){
    long long int n;
    cin >> n;
    string cows;
    cin >> cows;
    long long int cnt = 0;

    long long int breeds[500001][2];
    long long int gCnt = 0, hCnt = 0;
    breeds[0][0] = 0;
    breeds[0][1] = 0;

    for(long long int idx = 1; idx <= n; idx++){
        if(cows[idx-1] == 'G'){
            gCnt++;
        }else{
            hCnt++;
        }
        breeds[idx][0] = gCnt;
        breeds[idx][1] = hCnt;
        // cout << breeds[idx][0] << ' ' << breeds[idx][1] << '\n';
    }

    // cout <<"_____________________\n";

    for(long long int size = 3; size <= n; size++){
        // cout << "SIZE: " << size << '\n';
        for(long long int start = 1; start <= n-size+1; start++){
            long long int g, h;
            // cout << start+size-1 << ' ' <<  start-1 << '\n';
            g = breeds[start+size-1][0] - breeds[start-1][0];
            h = breeds[start+size-1][1] - breeds[start-1][1];
            // cout << "values: "<< g << ' ' <<  h << '\n';
            // cout << breeds[start+size-1][0] << ' '<< breeds[start-1][0] << '\n';
            // string temp = cows.substr(start, size);
            // int gCnt = 0, hCnt = 0;
            // for(int idx = 0; idx < size; idx++){
            //     if(temp[idx] == 'G'){
            //         gCnt++;
            //     } else{
            //         hCnt++;
            //     }
            // }
            if(g == 1 || h == 1){
                cnt++;
            }
            // cout << start << ' ';
        }
        // cout << '\n';
    }
    cout << cnt << '\n';
    return 0;
}