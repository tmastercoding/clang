#include <iostream>
using namespace std;

int main(){
    int n, moves[100001][3];
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
        if(move == 'P'){
            moves[i+1][0]++;
        } else if(move == 'H'){
            moves[i+1][1]++;
        } else{
            moves[i+1][1]++;
        }
    }

    int first, second;
    if(moves[n][0] > moves[n][1] || moves[n][0] > moves[n][2]){
        first = 0;
        if(moves[n][1] > moves[n][2])
    }

    return 0;
}