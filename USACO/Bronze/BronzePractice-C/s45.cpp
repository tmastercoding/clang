#include <iostream>
using namespace std;

int main(){
    // freopen("4.in", "r", stdin);
    int n;
    long long int t;
    cin >> n >> t;

    long long int day, bales;
    long long int ateBales = 0;
    long long int storage = 0, ateTil = 0;

    for(int idx = 0; idx < n; idx++){
        cin >> day >> bales;
        if(day <= t){
            if(storage!= 0){
                ateTil += storage;
                if(ateTil+storage <= day){
                    ateBales += storage;
                    storage = 0;
                    // ateTil += storage;
                } else{
                    // cout << " asdf\n";
                    if(bales > t){
                        ateBales += t;
                        storage -= t;
                    } else{
                        // ateBales += day;
                        // storage -= day;
                        if(ateTil < day){
                            ateBales += t-day+1;
                            storage -= t-day+1;
                            ateTil = t;

                        }
                    }
                    
                    // ateTil += storage;
                    // if(ateTil > t){
                    //     ateTil = t;
                    // }
                }
            }
            storage += bales;
        }
        // cout << ateBales << ' '   << storage << ' ' << ateTil << '\n';
    }
    if(storage!= 0){
        if(ateTil < day){
            if(ateTil+storage <= t){
                ateBales += storage;
                storage = 0;
                ateTil += storage;
            } else{
                ateBales += t-day+1;
                storage -= t-day+1;
                ateTil = t;
            }

        }
    }
    // cout << ateBales << ' ' << storage << ' ' << ateTil << '\n';

    cout << ateBales << '\n';
    return 0;
}