#include <iostream>
#include <set>
using namespace std;

int main(){
    int n;
    set<long long> s;
    long long x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        s.insert(x);
    }

    cout << s.size()<< '\n';
    return 0;
}