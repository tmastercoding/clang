#include <iostream>
using namespace std;

int main(){
    // freopen("hps.in", "r", stdin);
    // freopen("hps.out", "w", stdout);
    int n, moves[100010][3];
    cin >> n;

    moves[0][0] = 0;
    moves[0][1] = 0;
    moves[0][2] = 0;
    char move;
    for(int i = 0; i < n; i++){
        cin >> move;
        moves[i+1][0] = moves[i][0];
        moves[i+1][1] = moves[i][1];
        moves[i+1][2] = moves[i][2];
        if(move == 'H'){
            moves[i+1][0]++;
        } else if(move == 'P'){
            moves[i+1][1]++;
        } else{
            moves[i+1][2]++;
        }
    }

    int cnt, maxCnt = 0;
    for(int idx = 0; idx <= n; idx++){
        // cout << moves[idx][0] << ' ' << moves[idx][1] << ' ' << moves[idx][2] << '\n';
        cnt = 0;
        if(moves[idx][0] > moves[idx][1] && moves[idx][0] > moves[idx][2]){
            cnt += moves[idx][0];
        } else if(moves[idx][1] > moves[idx][0] && moves[idx][1] > moves[idx][2]){
            cnt += moves[idx][1];
        } else{
            cnt += moves[idx][2];
        }
        if(n != idx){
            int hoof, paper, scissors;
            hoof = moves[n][0] - moves[idx][0];
            paper = moves[n][1] - moves[idx][1];
            scissors = moves[n][2] - moves[idx][2];
            if(hoof > scissors && hoof > paper){
                cnt += hoof;
            } else if(paper > scissors && paper > hoof){
                cnt += paper;
            } else{
                cnt += scissors;
            }
        }
        if(cnt > maxCnt){
            maxCnt = cnt;
        }
    }
    cout << maxCnt << '\n';
    return 0;
}