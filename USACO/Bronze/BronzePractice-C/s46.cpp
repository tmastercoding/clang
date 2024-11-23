// Stamp Grid
#include <iostream>
#include <string>
using namespace std;

int main(){
    freopen("2.in", "r", stdin);

    int t;
    cin >> t;
    for(int i = 0; i < t; i++){

        int n, k;
        cin >> n;
        string painting[20], canvas[20];
        for(int idx = 0; idx < n; idx++){
            cin >> painting[idx];
        }
        for(int y = 0; y < n; y++){
            for(int x = 0; x < n; x++){
                canvas[y][x] = '.';
            }
        }

        cin >> k;
        string stamp[20];
        string stamps[4][20];
        for(int idx = 0; idx < k; idx++){
            cin >> stamp[idx];
            stamps[0][idx] = stamp[idx];
        }

        int ax = 0, ay = 0;
        for(int y = 0; y < k; y++){
            for(int x = 0; x < k; x++){
                stamps[1][y][x] = stamp[x][y];
            }
        }

        ay = 0;
        for(int y = k-1; y >-1; y--){
            ax = 0;
            for(int x = k-1; x > -1; x--){
                stamps[2][ay][ax] = stamp[y][x];
                ax++;
            }
            ay++;
        }

        ay = 0;
        for(int y = k-1; y >-1; y--){
            ax = 0;
            for(int x = k-1; x > -1; x--){
                stamps[3][ay][ax] = stamp[x][y];
                ax++;
            }
            ay++;
        }

        for(int y = 0; y <= n-k; y++){
            for(int x = 0; x <= n-k; x++){
                // cout << y << ',' << x << ' ';
                for(int r= 0; r < 4; r++){
                    bool isMatch = true;
                    for(int extendy = 0; extendy < k; extendy++){
                        for(int extendx = 0; extendx < k; extendx++){
                            if(stamps[r][extendy][extendx] == '.' || stamps[r][extendy][extendx] == painting[y+extendy][x+extendx]){
                                continue;
                            }
                            isMatch = false;
                        }
                    }
                    if(isMatch){
                        for(int extendy = 0; extendy < k; extendy++){
                            for(int extendx = 0; extendx < k; extendx++){
                                // cout << stamps[r][extendy][extendx];
                                if(canvas[y+extendy][x+extendx] == '*' &&  stamps[r][extendy][extendx] == '.'){
                                    canvas[y+extendy][x+extendx] = '-';
                                } else if(canvas[y+extendy][x+extendx] == '.' &&  stamps[r][extendy][extendx] == '*'){
                                    canvas[y+extendy][x+extendx] = '-';
                                } else{
                                    if(canvas[y+extendy][x+extendx] != '-'){
                                        canvas[y+extendy][x+extendx] = stamps[r][extendy][extendx];

                                    }
                                }
                            }
                            // cout << '\n';
                        }
                        // break;
                    }
                    // for(int y = 0; y < n; y++){
                    //     for(int x = 0; x < n; x++){
                    //         cout << canvas[y][x];
                    //     }
                    //     // cout << '\n';
                    // }
                }
            }
            // cout << '\n';
        }
        
        bool isValid = true;
        for(int y = 0; y < n; y++){
            for(int x = 0; x < n; x++){
                if(i == 6){
                    cout << canvas[y][x];

                }
                if(canvas[y][x] == '-' || canvas[y][x] == painting[y][x]){
                    continue;
                }
                if(i == 6){
                    cout << x << y;
                }
                isValid = false;

            }
            if(i == 6){
                cout << '\n';

            }
        }
        
        if(isValid){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }
    return 0;
}