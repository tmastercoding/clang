// Candy Cane Feast 31063
#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    long long int cows[200000], candies[200000];
    
    for(int i = 0; i < n; i++){
        cin >> cows[i];
    }
    for(int i = 0; i < m; i++){
        cin >> candies[i];
    }

    long long int eaten, temp;

    for(int i = 0; i < m; i++){
        eaten = 0;
        for(int j = 0; j < n; j++){
            if(cows[j] > eaten){
                if(cows[j] > candies[i]){
                    temp = eaten;
                    eaten = candies[i];
                    cows[j] += candies[i] - temp;
                    break;
                } else{
                    temp = eaten;
                    eaten = cows[j];
                    cows[j] += cows[j] - temp;

                }
            }
        }
        // for(int i = 0; i < n; i++){
        //     cout << cows[i] << ' ';
        // }
        // cout << '\n';
    }

    for(int i = 0; i < n; i++){
        cout << cows[i] << '\n';
    }

    return 0;
}