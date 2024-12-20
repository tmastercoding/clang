#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
    int n, f;
    string s;
    cin >> n >> f >> s;
    set<string> moos;
    string moo;

    for(char first = 'a'; first <= 'z'; first++){
        for(char second = 'a'; second <= 'z'; second++){
            if(first == second){
                continue;
            }
            int cnt = 0;
            int broken = 1;
            int oCnt = 0;
            moo = first;
            moo += second;
            moo+= second;
            for(int idx = n-3; idx > -1; idx--){
                oCnt = 0;
                if(s[idx] == first){
                    oCnt++;
                } 
                if(s[idx+1] == second){
                    oCnt++;
                }
                if( s[idx+2] == second){
                    oCnt++;
                } 
                if(oCnt == 3){
                    cnt++;
                    idx-=2;
                } else if(oCnt == 2 && broken){
                    cnt++;
                    idx-=2;
                    broken = 0;
                }
            }
            // cout << moo << '\n';
            // if(moo == "aqq"){
            //     cout << cnt << '\n';
            //     cout << oCnt << '\n';
            // } 
            if(cnt >= f){
                moos.insert(moo);
            }
        }
    }

    cout << moos.size() << '\n';

    for(set<string>::iterator it = moos.begin(); it != moos.end(); it++){
        cout << *it << '\n';
    }
    return 0;
}