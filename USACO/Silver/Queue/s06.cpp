#include <iostream>
#include <deque>
#include <string>
#include <string.h>
using namespace std;

int main(){
    
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t = 0;
    cin >> t;
    for(int i = 0; i < t; i++){

        deque<int> d, tmpDeque;
        string command, buffer;
        int n;
        cin >> command >> n >> buffer;
        buffer.erase(buffer.size()-1 , 1);
        buffer.erase(0, 1);
        char temp[400000],* number;
        strcpy(temp, buffer.c_str());
        number = strtok(temp, ",");

        while(number != NULL){
            d.push_back(atoi(number));
            number = strtok(NULL, ",");
        }
        bool error = false, reverse = false;
        for(int idx = 0; idx < command.size(); idx++){
            if(command[idx] == 'R'){
                reverse = !reverse;
            } else{
                if(d.empty()){
                    error = true;
                    break;
                } else{
                    if(reverse){
                        d.pop_back();
                    } else{
                        d.pop_front();
                    }
                }
            }
        }

        if(error){
            cout << "error\n";
        } else{
            cout << '[';
            int s = d.size();
            if(!reverse){
                for(int i = 0; i < s; i++){
                    cout << d.front();
                    if(i!=s-1){
                        cout << ',';
                    }
                    d.pop_front();
                }
            } else{
                for(int i = 0; i < s; i++){
                    cout << d.back();
                    if(i!=s-1){
                        cout << ',';
                    }
                    d.pop_back();
                }
            }
            cout << "]\n";
        }
    }
    

    return 0;
}