// 듣보잡 1764
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(){
    int n, m;
    set<string> s, out;
    string str;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> str;
        s.insert(str);
    }
    
    for(int i = 0; i < m; i++){
        cin >> str;
        if(s.find(str) != s.end()){
            out.insert(str);
        }
    }
    cout << out.size() << '\n';
    for(string str: out){
        cout << str << '\n';
    }

    return 0;
}