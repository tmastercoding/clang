#include <iostream>
#include <string>
using namespace std;

int main(){
    int size, time;
    cin >> size >> time;
    string exchange;
    cin >> exchange;

    long long int limits[200000];
    long long int cows[200000];
    char exch[200000];
    for(int idx = 0; idx < size; idx++){
        cin >> limits[idx];
        cows[idx] = limits[idx];
        exch[idx] = exchange[idx];
    }

    for(int curTime = 0; curTime < time; curTime++){
        for(int idx = 0; idx < size; idx++){
            if(cows[idx] > 0){
                if (idx == 0){
                    if(exch[idx] == 'R'){
                        cows[idx+1] += 1;
                        cows[idx] -= 1;
                    } else{
                        cows[size-1] += 1;
                        cows[idx] -= 1;
                    }
                } else if(idx == size-1){
                    if(exch[idx] == 'R'){
                        cows[0] += 1;
                        cows[idx] -= 1;
                    } else{
                        cows[size-2] += 1;
                        cows[idx] -= 1;
                    }
                } else{
                    if(exch[idx] == 'R'){
                        cows[idx+1] += 1;
                        cows[idx] -= 1;
                    } else{
                        cows[idx-1] += 1;
                        cows[idx] -= 1;
                    }
                } 
                
            }
        }
        for(int idx = 0; idx < size; idx++){
            if(cows[idx] > limits[idx]){
                cows[idx] = limits[idx];
            }
            cout << cows[idx] << ' ';
        }
        cout << '\n';
    }
    
    int milk = 0;
    for(int idx = 0; idx < size; idx++){
        milk += cows[idx];
    }
    cout << milk << '\n';
    return 0;
}
