#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
    int n;
    // cow name: {from Bessie, year of:}
    map<string, pair<int, string>> cows;
    string pre, t1, t2, relation, animal, t3, t4, post;
    map<string, int> years = {{"Ox", 0}, {"Tiger", 1}, {"Rabbit", 2}, {"Dragon", 3}, {"Snake", 4}, {"Horse", 5}, {"Goat", 6}, {"Monkey", 7}, {"Rooster", 8}, {"Dog", 9}, {"Pig", 10}, {"Rat", 11}};

    cin >> n;
    for(int idx = 0; idx < n; idx++){
        cin >> pre >> t1 >> t2 >> relation >> animal >> t3 >> t4 >> post;
        int preDx, postDx;
        preDx = years[animal];
        postDx = years[cows[post].second];
        int dif;
        if(relation == "previous"){
            if(preDx < postDx){
                dif = postDx-preDx;
            } else if(preDx > postDx){
                dif = postDx + 12-preDx;
            } else{
                dif = 12;
            }
            dif *= -1;
        } else{
            if(preDx > postDx){
                dif = preDx-postDx;
            } else if(preDx < postDx){
                dif = 12-postDx + preDx;
            } else{
                dif = 12;
            }
        }
        int fromB = 0;
        if(post == "Bessie"){
            fromB = dif;
        } else{
            fromB = cows[post].first+dif;
            // if(dif < 0){
            //     fromB--;
            // } else{
            //     fromB++;
            // }
        }
        // cout << preDx << ' ' << postDx << ' ' << dif << ' ' << fromB << '\n';
        cows[pre] = {fromB, animal};
    }
    cout << abs(cows["Elsie"].first) << '\n';
    return 0;
}