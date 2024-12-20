#include <iostream>
#include <string>
using namespace std;

int arr[4], check[4], cubes[4][26];
bool work = false;
void f(int cur, string word){
    if(cur == word.size()){
        if(!work){
            work = true;
            for(int idx = 0; idx < word.size(); idx++){
                if(!cubes[arr[idx]][word[idx]-'A']){
                    work = false;
                }
            }
        }
    }

    for(int idx = 0; idx < 4; idx++){
        if(check[idx] == 0){
            check[idx] = 1;
            arr[cur] = idx;
            f(cur+1, word);
            check[idx] = 0;
        }
    }
}

int main(){
    int n;
    cin >> n;
    string temp, word;
    for(int idx = 0; idx < 4; idx++){
        cin >> temp;
        for(char ch: temp){
            cubes[idx][ch-'A']++;
        }
    }

    for(int idx = 0; idx < n; idx++){
        cin >> word;
        work = false;
        f(0, word);
        if(work){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
        
    }
    return 0;
}