// 스택 수열 1874
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    int n; 
    cin >> n;
    int arr[100000];
    for(int idx = 0; idx < n; idx++){
        cin >> arr[idx];
    }
    stack<int> s;

    int largest = 0;
    bool possible = true;
    string commands = "";
    
    for(int idx = 0; idx < n; idx++){
        if(s.empty()){
            for(int jdx = largest+1; jdx <= arr[idx]; jdx++){
                s.push(jdx);    
                commands += "+\n";
            }
            largest = arr[idx];
            s.pop();
            commands += "-\n";
        } else{
            if(s.top() < arr[idx]){
                for(int jdx = largest+1; jdx <= arr[idx]; jdx++){
                    s.push(jdx);    
                    commands += "+\n";
                }
                largest = arr[idx];
                s.pop();
                commands += "-\n";
            } else{
                if(s.top() == arr[idx]){
                    s.pop();
                    commands += "-\n";
                } else{
                    possible = false;
                    break;
                }
            }
        }
    }
    if(possible){
        cout << commands;
    } else{
        cout << "NO\n";
    }

    return 0;
}