#include <iostream>
#include <set>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    multiset<long long> tickets;
    long long maxPrice[200000], val;

    for(int i = 0; i < n; i++){
        cin >> val;
        tickets.insert(val);
    }

    for(int i = 0; i < m; i++){
        cin >> maxPrice[i];
    }

    for(int i = 0; i < m; i++){
        auto it = tickets.lower_bound(maxPrice[i]);
        bool hasPrint = false;
        // cout << *it << '\n';
        if(it != tickets.end()){
            if(*it == maxPrice[i]){
                cout << *it << '\n';
                hasPrint = true;
                tickets.erase(tickets.find(*it));
            } else{
                if(it != tickets.begin()){
                    it--;
                    if(*it <= maxPrice[i]){
                        cout << *it << '\n';
                        hasPrint = true;
                        tickets.erase(tickets.find(*it));
                    }
                }
            } 
        } else{
            if(it != tickets.begin()){
                it--;
                if(*it <= maxPrice[i]){
                    cout << *it << '\n';
                    hasPrint = true;
                    tickets.erase(tickets.find(*it));
                }
            }
        }
        if(!hasPrint) cout << -1 << '\n';
    }

    return 0;
}