#include <iostream>
#include <string>
using namespace std;

int main(){

    // cin.tie(NULL);
    // ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string cows;
    cin >> cows;
    
    // start, end
    int gCows[100000][2], hCows[100000][2];
    int end, g = 0, h = 0;
    int firstG, lastG, firstH, lastH;
    
    for(int idx = 0; idx < n; idx++){
        cin >> end;
        if(cows[idx] == 'G'){
            if(g == 0){
                firstG = idx;
            }
            gCows[g][0] = idx;
            gCows[g++][1] = end-1;
            lastG = idx;
        } else{
            if(h == 0){
                firstH = idx;
            }
            hCows[h][0] = idx;
            hCows[h++][1] = end-1;
            lastH = idx;
        }
    }
    // cout << firstH << ' ' << lastH << '\n';
    bool gAll = false, hAll = false;
    int cnt = 0;
    for(int idx = 0; idx < g; idx++){
        gAll = false;
        if(gCows[idx][0] <= firstG && lastG <= gCows[idx][1]){
            gAll = true;
        }
        // cout << gCows[idx][0] << ":\n";
        for(int jdx = 0; jdx < h; jdx++){
            cout << idx << ' ' << jdx << '\n';
            hAll = false;
            if(hCows[jdx][0] <= firstH && lastH <= hCows[jdx][1]){
                hAll = true;
            }
            // cout << hCows[jdx][0] << '_';
            if(gAll && hAll){
                // cout << gCows[idx][0]+1 << ' ' << hCows[jdx][0]+1 << '\n';
                cnt++;
            } else if(!gAll && hAll){
                if(gCows[idx][0] <= hCows[jdx][0] && hCows[jdx][0] <= gCows[idx][1]){
                    cnt++;
                    // cout << gCows[idx][0]+1 << ' ' << hCows[jdx][0]+1 << '\n';
                }
            } else if(gAll && !hAll){
                if(hCows[jdx][0] <= gCows[idx][0] && gCows[idx][0] <= hCows[jdx][1]){
                    cnt++;
                    // cout << gCows[idx][0]+1 << ' ' << hCows[jdx][0]+1 << '\n';
                }
            } else{
                if(hCows[jdx][0] <= gCows[idx][0] && gCows[idx][0] <= hCows[jdx][1] && gCows[idx][0] <= hCows[jdx][0] && hCows[jdx][0] <= gCows[idx][1]){
                    cnt++;
                    cout << gCows[idx][0]+1 << ' ' << hCows[jdx][0]+1 << '\n';
                }
            }
        }
        // cout << '\n';
    }
    cout << cnt << '\n';
    return 0;
}