#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, q, breed, sums[100001][3] = {0};
    cin >> n >> q;
    sums[0][0] = 0;
    sums[0][1] = 0;
    sums[0][2] = 0;
    for(int i = 0; i < n; i++){
        cin >> breed;
        sums[i+1][0] = sums[i][0];
        sums[i+1][1] = sums[i][1];
        sums[i+1][2] = sums[i][2];
        sums[i+1][breed-1] = sums[i][breed-1]+1;
    }

    int start, end;
    for(int i = 0; i < q; i++){
        cin >> start >> end;
        cout << sums[end][0]-sums[start-1][0] << ' ' << sums[end][1]-sums[start-1][1] << ' '<< sums[end][2]-sums[start-1][2] << '\n';
    }
    return 0;
}