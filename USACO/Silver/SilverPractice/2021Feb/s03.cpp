#include <iostream>
using namespace std;

int main(){
    int n, num;
    int imap[500][500], notimap[500][500];
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> num;
            if(num >= 100){
                imap[i][j] = 1;
            } else{
                imap[i][j] = 0;
            }

            if(num > 100){
                notimap[i][j] = 1;
            } else{
                notimap[i][j] = 0;
            }
        }
    } 

    int checks[500];
    long long icnt = 0, noticnt = 0;
    for(int i = 0; i < n; i++){
        for(int x = 0; x < n; x++) checks[x] = 1;
        for(int j = i; j < n; j++){
            int continuous = 0;
            for(int k = 0; k < n; k++){
                // update
                if(checks[k]){
                    if(imap[j][k] == 0){
                        checks[k] = 0;
                    }
                }
                if(checks[k]){
                    continuous++;
                    icnt+=continuous;
                } else{
                    continuous = 0;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int x = 0; x < n; x++) checks[x] = 1;
        for(int j = i; j < n; j++){
            int continuous = 0;
            for(int k = 0; k < n; k++){
                // update
                if(checks[k]){
                    if(notimap[j][k] == 0){
                        checks[k] = 0;
                    }
                }
                if(checks[k]){
                    continuous++;
                    noticnt+=continuous;
                } else{
                    continuous = 0;
                }
            }
        }
    }

    cout << icnt-noticnt << '\n';


    return 0;
}