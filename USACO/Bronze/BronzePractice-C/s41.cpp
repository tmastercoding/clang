#include <iostream>
#include <string>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    string temp;
    int result;

    int zeroes[100][100], ones[100][100];
    int z = 0, o = 0;
    for(int idx = 0; idx < m; idx++){
        cin >> temp >> result;
        for(int jdx = 0; jdx < n; jdx++){
            if(result == 0){
                zeroes[z][jdx] = temp[jdx]-'0';
            } else{
                ones[o][jdx] = temp[jdx]-'0';
            }
        }
        if(result == 0){
            z++;
        } else{
            o++;
        }
    }

    for(int idx = 0; idx < z; idx++){
        for(int jdx = 0; jdx < n; jdx++){
            cout << zeroes[idx][jdx] << ' ';
        }
        cout << '\n';
    }
    
    for(int idx = 0; idx < o; idx++){
        for(int jdx = 0; jdx < n; jdx++){
            cout << ones[idx][jdx] << ' ';
        }
        cout << '\n';
    }
    return 0;
}