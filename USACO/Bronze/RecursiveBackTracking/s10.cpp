// 스타트와 링크 14889

#include <iostream>
using namespace std;

int n, m;
int org[20][20], arr[20], check[20], sCheck[100000], sArr[20];
int skill = 0, minDif = 99999999;

void getSkill(int j, int team[20]){
    if(j == 0){
        skill = 0;
    }
    if(j == 2){
        // cout << sArr[0] << ' ' << sArr[1] << '\n';
        skill += org[sArr[0]][sArr[1]];
        // cout << skill << '\n';
        return;
    }
    for(int x = 0; x < m; x++){
        if(sCheck[team[x]] == 0){
            sCheck[team[x]] = 1;
            sArr[j] = team[x];
            getSkill(j+1, team);
            sCheck[team[x]] = 0;
        }
    }
}

void f(int i){
    if (i == m){
        int team[20];
        int t = 0;
        for(int x = 0; x < n; x++){
            bool hasFound = false;
            for(int j = 0; j < m; j++){
                if(arr[j] == x){
                    hasFound = true;
                }
            }
            if(!hasFound){
                team[t++] = x;
            }
        }
        getSkill(0, arr);
        int temp = skill;
        getSkill(0, team);

        if(abs(skill-temp) < minDif){
            minDif = abs(skill-temp);
        }
        return;
    }
    int start = 0;
    if(i != 0){
        start = arr[i-1];
    }
    for(int x = start; x < n; x++){
        if(check[x] == 0){
            check[x] = 1;
            arr[i] = x;
            f(i+1);
            check[x] = 0;
        }
    }
}

int main(){
    cin >> n;
    m = n/2;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> org[i][j];
        }
    }

    f(0);

    // for(int idx = 0; idx < sIdx; idx++){
    //     if(skills[idx] < minDif){
    //         minDif = skills[idx];
    //     }
    // }    

    cout << minDif << '\n';
    return 0;
}
