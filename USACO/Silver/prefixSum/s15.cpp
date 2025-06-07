#include <iostream>
#include <string>
using namespace std;

int main(){
    int n, m;
    int flag[51][3];
    string buffer;
    flag[0][0] = 0, flag[0][1] = 0, flag[0][2] = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> buffer;
        flag[i][0] = flag[i-1][0], flag[i][1] = flag[i-1][1], flag[i][2] = flag[i-1][2];
        for(int j = 0; j < m; j++){
            if(buffer[j] == 'W'){
                flag[i][0]++;
            } else if(buffer[j] == 'R'){
                flag[i][1]++;
            } else if(buffer[j] == 'B'){
                flag[i][2]++;
            }
        }
    }

    // for(int i = 1; i <= n; i++){
    //     cout << flag[i][0] << ' ' << flag[i][1] << ' ' << flag[i][2] << '\n';
    // }

    int cnt = 0, min = 2500;
    for(int w = 1; w <= n-2; w++){
        for(int b = w+1; b <= n-1; b++){
            // cout << w << ' ' << b << '\n';
            cnt = w*m-flag[w][0];
            // cout << w*m-flag[w][0] << '\n';
            cnt += (b-w)*m-(flag[b][2]-flag[w][2]);
            // cout << (b-w)*m-(flag[b][2]-flag[w-1][2]) << '\n';
            cnt += (n-b)*m-(flag[n][1]-flag[b][1]);
            // cout << flag[b][1] << '\n';
            if(min > cnt) min = cnt;
        }
    }
    cout << min << '\n';
    return 0;
}