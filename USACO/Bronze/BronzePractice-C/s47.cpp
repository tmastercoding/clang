// Watching Mooloo
#include <iostream>
using namespace std;

int main(){
    int n;
    long long int k;
    cin >> n >> k;

    long long int days[100000];
    for(int i = 0; i < n; i++){
        cin >> days[i];
    }

    long long int prevDay = days[0], moonies = k+1;
    long long int con = 0, sep = 0;
    for(int idx = 1; idx < n; idx++){
        con = days[idx]-prevDay;
        sep = k+1;
        if(con > sep){
            moonies += sep;
        } else{
            moonies += con;
        }
        prevDay = days[idx];
    }

    cout << moonies << '\n';
    return 0;
}