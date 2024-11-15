#include <iostream>
using namespace std;

int n, m;
int cows[20][3];
int aircons[20][4];
int arr[10], check[10];
int minMoney = 100000;
void f(int i, int choose){
    if(i == choose){
        int totMoney = 0;
        int coolness[100] = {0};
        for(int idx = 0; idx < choose; idx++){
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
        if(isValid && totMoney < minMoney){
            minMoney = totMoney;
        }
        return;
    } 
    int start = 0;
    if(i != 0){
        start = arr[i-1];
    }

    for(int x = start; x < m; x++){
        if(check[x] == 0){
            arr[i] = x;
            check[x] = 1;
            f(i+1, choose);
            check[x] = 0;
        }
    }
}

int main(){
    cin >> n >> m;
    for(int idx = 0; idx < n; idx++){
        cin >> cows[idx][0] >> cows[idx][1] >> cows[idx][2];
        cows[idx][0]--;
        cows[idx][1]--;
    }
    for(int idx = 0; idx < m; idx++){
        cin >> aircons[idx][0] >> aircons[idx][1] >> aircons[idx][2] >> aircons[idx][3];
        aircons[idx][0]--;
        aircons[idx][1]--;
    }
    
    for(int choose = 1; choose <= m; choose++){
        f(0, choose);
    }

    cout << minMoney << '\n';

    return 0;
}