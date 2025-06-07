// 인간-컴퓨터 상호작용 16139
#include <iostream>
#include <string>
using namespace std;

int arr[200002][30] = {};
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string str;
    int q;
    cin >> str >> q;
    char ch;
    int l, r;
    for(int i = 0; i < str.size(); i++){
        for(int j = 0; j < 26; j++){
            if(i > 0){
                arr[i][j] = arr[i-1][j];
            } else{
                arr[i][j] = 0;
            }
        }
        arr[i][str[i]-'a']++;
    }
    for(int idx = 0; idx < q; idx++){
        cin >> ch >> l >> r;
        if(l > 0){
            cout << arr[r][ch-'a']-arr[l-1][ch-'a'] << '\n';
        } else{
            cout << arr[r][ch-'a'] << '\n';
        }
    }
    return 0;
}