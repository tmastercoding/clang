#include <iostream>
using namespace std;

int main(){
    freopen("4.in", "r", stdin);
    int n;
    long long int t;
    cin >> n >> t;

    long long int day, bales;
    long long int ateBales = 0;
    long long int canEatTil = 0;

    for(int idx = 0; idx < n; idx++){
        cin >> day >> bales;
        if(day <= t){
            if(day+bales <= t){
                canEatTil = day-1+bales;
                ateBales += bales;
            } else{
                canEatTil = t; 
                if(ateBales >= t){
                    ateBales = t;
                } else{
                    if(t-day < bales){
                        ateBales += t-day;
                    } else{
                        ateBales += bales;
                    }
                }
            }
        }
        
        cout << ateBales << ' '  << canEatTil << '\n';
    }
    
    cout << ateBales << '\n';
    return 0;
}