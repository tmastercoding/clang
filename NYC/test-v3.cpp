#include <iostream>
#include <string>
#include <sstream>
#include <vector>
// #include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string buffer;
    string text;
    ll cowSize, candySize = 0;
    vector<ll> cows;
    vector<ll> candies;
    vector<ll> candy;
    ll eatHeight = 0;
    ll ogHeight = 0;
    ll temp = 0;

    // input sizes
    getline(cin, text);
    istringstream iss(text);
    iss >> buffer;
    cowSize = stoi(buffer);
    iss >> buffer;
    candySize = stoi(buffer);

    // cout << cowSize << " " << candySize << endl;
    // input vectors
    getline(cin, text);
    istringstream jss(text);
    while(jss >> buffer){
        cows.push_back(stoi(buffer));
    }

    getline(cin, text);
    istringstream kss(text);
    while(kss >> buffer){
        candies.push_back(stoi(buffer));
    }
    auto print = []( const ll &n ) { cout << n << ' '; };
    // cout << endl;
    // for_each(candies.begin(), candies.end(), print);
    // cout << endl;

    for(ll idx = 0; idx < candySize; idx++){
        ogHeight = candies.at(idx);
        eatHeight = 0;

        for(ll jdx = 0; jdx < cowSize; jdx++){
            if(eatHeight < cows.at(jdx)){
                if (cows.at(jdx) > ogHeight){
                    eatHeight = ogHeight;
                    cows.at(jdx) += ogHeight;
                    break;
                } else if (eatHeight != ogHeight){
                    temp = cows.at(jdx);
                    cows.at(jdx) += cows.at(jdx) - eatHeight;
                    eatHeight = temp;
                }
            }
            // cout << eatHeight << endl;
        }
    }

    // cout << "7" << endl << "2" << endl << "7" << endl;
    for(ll cow : cows){
        cout << cow << endl;
    }

    return 0;
}