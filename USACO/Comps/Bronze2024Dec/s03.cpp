#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
    int n, f;
    string s;
    cin >> n >> f >> s;
    set<string> moos;

    // look for 2 at front
    string moo, temp;
    for(int idx = 0; idx < n-2; idx++){
        if(s[idx+2] == s[idx+1] || s[idx] == s[idx+1]){
            continue;
        }
        moo = s[idx];
        moo += s[idx+1];
        moo += s[idx+1];
        int cnt = 1;
        for(int jdx = idx+3; jdx < n-2; jdx++){
            temp = s[jdx];
            temp += s[jdx+1];
            temp +=s[jdx+2];
            if(temp == moo){
                cnt++;
                jdx+=3;
            }
        }
        if(cnt >= f){
            moos.insert(moo);
        }
    }
    // look for 2 at back
    for(int idx = 0; idx < n-2; idx++){
        if(s[idx+1] != s[idx+2] || s[idx+1] != s[idx]){
            continue;
        }
        for(char ch = 'a'; ch <= 'z'; ch++){
            if(s[idx] != ch && s[idx+1] != ch){
                moo = ch;
                moo += s[idx+1];
                moo += s[idx+2];
                int cnt = 1;
                for(int jdx = idx+3; jdx < n-2; jdx++){
                    temp = s[jdx];
                    temp += s[jdx+1];
                    temp += s[jdx+2];
                    if(temp == moo){
                        cnt++;
                        jdx+=3;
                    }
                }
                if(cnt >= f){
                    moos.insert(moo);
                }
            }
        }
    }

    // first and third
    for(int idx = 0; idx < n-2; idx++){
        if(s[idx+2] == s[idx+1] ){
            continue;
        }
        moo = s[idx];
        moo += s[idx+2];
        moo += s[idx+2];
        int cnt = 1;
        for(int jdx = idx+3; jdx < n-2; jdx++){
            temp = s[jdx];
            temp += s[jdx+1];
            temp +=s[jdx+2];
            if(temp == moo){
                cnt++;
                jdx+=3;
            }
        }
        if(cnt >= f){
            moos.insert(moo);
        }
    }
    
    // look for full
    for(int idx = 0; idx < n-2; idx++){
        if(s[idx+1] != s[idx+2] || s[idx] == s[idx+1]){
            continue;
        }
        moo = s[idx];
        moo += s[idx+1];
        moo += s[idx+2];
        // cout << moo << '\n';
        int broken = 1;
        int cnt = 1;
        for(int jdx = idx+3; jdx < n-2; jdx++){
            temp = s[jdx];
            temp += s[jdx+1];
            temp += s[jdx+2];
            if(temp == moo){
                cnt++;
                jdx+=3;
            } else if(broken > 0 && temp[0]+temp[1] == moo[0]+moo[1]){
                cnt++;
                broken = 0;
                jdx+=3;
            } else if(broken > 0 && temp[1]+temp[2] == moo[1]+moo[2]){
                cnt++;
                broken = 0;
                jdx+=3;
            }
        }
        if(cnt >= f){
            moos.insert(moo);
        }
    }

    cout << moos.size() << '\n';

    for(set<string>::iterator it = moos.begin(); it != moos.end(); it++){
        cout << *it << '\n';
    }

    return 0;
}