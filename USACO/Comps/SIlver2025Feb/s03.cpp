#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int cas = 0; cas < t; cas++){

        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        
        bool flag = true;
        long long cnt = 0;
        while(c > a && d > b){
            if(c >= d){
                cnt += c/d;
                c = c % d;
            } else{
                cnt += d/c;
                d = d % c;
            }
            // cout << c << ' ' << d << '\n';
        }
        if(a == c && b == d){
            flag = true;
        } else if (a > c || b > d){
            flag = false;
        } else if(b == d){
            if((c-a)%b == 0 ){
                cnt += (c-a)/b;
            } else{
                flag = false;
            }
        } else if(a == c){
            if((d-b)%a == 0){
                cnt += (d-b)/a;
            } else{
                flag = false;
            }
        }
        if(flag){
            cout << cnt << '\n';
        } else{
            cout << "-1\n";
        }
    }
    // cout << c << ' ' << d << '\n';
    return 0;
}