// 최소 힙 1927
#include <iostream>
#include <set>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    long long n;
    multiset<long long> s;
    long long num;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num;
        if(num){
            s.insert(num);
        } else{
            if(s.size()){
                cout << *(s.begin()) << '\n';
                s.erase(s.begin());
            } else{
                cout << "0\n";
            }
        }
    }

    return 0;
}