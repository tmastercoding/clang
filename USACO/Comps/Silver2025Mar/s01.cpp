#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int m, k;
        cin >> m >> k;
        vector<int> popCount, output;
        int i = 0;
        int temp = k;
        while(temp > 0){
            while(true){
                if(1 << (i+1) <= temp){
                    i++;
                } else{
                    break;
                }
            }
            popCount.push_back(1 << i);
            temp -= 1 <<i;
            i = 0;
        }
        
        int remainder = m;
        bool valid = true;
        for(int i = 0; i < popCount.size(); i++){
            // cout <<popCount[i] << '\n';
            if(!remainder){
                valid = false;
                break;
            }
            temp = 0;
            if(i < popCount.size()-1 || popCount[i] != 1){
                for(int j = 0; j < popCount[i]; j++){
                    temp += 1 << j;
                }
                output.push_back(temp);
                remainder-= temp;
            } else{
                // cout << remainder << '\n';
                int j = 0;
                while(!(remainder >> j & 1)){
                    j++;
                }
                remainder -= 1 << j;
                output.push_back(1 << j);
            }
            // cout << temp << '\n';
        }
        // cout <<remainder << '\n';
        if(remainder > -1 && remainder != 1 && valid){
    
            if(remainder & 1){
                output.push_back(1);
                remainder--;
                int i = 0;
                while(!(remainder >> i & 1)){
                    i++;
                }
                remainder -= 1 << i;
                output.push_back(1 << i);
            }
            if(remainder > 0){
                output.push_back(remainder/2);
                output.push_back(remainder/2);
            }
        
            cout << output.size() << '\n';
            for(int i = 0; i< output.size(); i++){
                cout << output[i] << ' ';
            }
            cout << '\n';
        } else{
            cout << -1 << '\n';
        }
    }
    return 0;
}