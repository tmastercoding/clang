// Palindrome Game 31648
#include <iostream>
#include <string>
using namespace std;

bool isPalin(int num){
    string temp = to_string(num);
    int len = temp.length();

    for(int idx = 0; idx < len/2; idx++){
        if(temp[idx] != temp[len-idx-1]){
            return false;
        }
    }
    return true;
}

int main(){

    int size;
    cin >> size;
    for(int cnt = 0; cnt < size; cnt++){
        int num = 0;
        cin >> num;
        char cur = 'B';
        while(num > 0){
            if(isPalin(num)){
                cout << cur << '\n';
                break;
            } else{
                int can = 0;
                bool hasFound = false;
                for(int sub = 1; sub < num; sub++){
                    if(isPalin(sub)){
                        can = sub;
                        if(!isPalin(num-sub)){
                            num -= sub;
                            hasFound = true;
                            break;
                        }
                    }
                }
                if(!hasFound){
                    num -= can;
                }
                if(cur == 'B'){
                    cur = 'E';
                } else{
                    cur = 'B';
                }
            }
        }
    }

    return 0;
}