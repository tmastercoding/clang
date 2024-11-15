#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    // start, end, cool
    int cows[20][3];
    for(int idx = 0; idx < n; idx++){
        cin >> cows[idx][0] >> cows[idx][1] >> cows[idx][2];
        cows[idx][0]--;
        cows[idx][1]--;
    }

    // start, end, cool, money
    int aircons[20][4];
    for(int idx = 0; idx < m; idx++){
        cin >> aircons[idx][0] >> aircons[idx][1] >> aircons[idx][2] >> aircons[idx][3];
        aircons[idx][0]--;
        aircons[idx][1]--;
    }

    int arr[3] = {0,2,3};
    int totMoney;
    int coolness[100] = {0};
    for(int idx = 0; idx < 3; idx++){
        for(int jdx = aircons[arr[idx]][0]; jdx <= aircons[arr[idx]][1]; jdx++){
            coolness[jdx] += aircons[arr[idx]][2];
        }
        totMoney += aircons[arr[idx]][3];
    }

    bool isValid = true;
    for(int idx = 0; idx < n; idx++){
        for(int jdx = cows[idx][0]; jdx <= cows[idx][1]; jdx++){
            if(coolness[jdx] < cows[idx][2]){
                isValid = false;
                break;
            }
        }
    }

    cout << isValid << '\n';

    return 0;
}