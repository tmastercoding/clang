#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    string text;
    vector<int> cows; 
    string temp;
    // int size = 3;
    int prev = 0;
    int minDif = 0;
    int maxDif = 0;
    int minChoice = 0;
    int maxChoice = 0;
    
    getline(cin, text);
    istringstream iss(text);
    
    while(iss >> temp){
        cows.push_back(stoi(temp));
    }

    auto print = []( const int &n ) { cout << n << ' '; };
    // for_each(cows.begin(), cows.end(), print);
    // cout << endl;

    sort(cows.begin(), cows.end());
    prev = cows.at(0);
    maxDif = cows.at(1) - prev;
    minDif = cows.at(1) - prev;

    prev = cows.at(1);
    if(cows.at(2) - prev > maxDif){
        maxDif = cows.at(2) - prev;
    }
    if(cows.at(2) - prev < minDif){
        minDif = cows.at(2) - prev;
    }
    // cout << maxDif << ' ' << minDif << endl;

    if (minDif == 1){
        if(maxDif == 1){
            minChoice = 0;
        } else{
            if (maxDif == 2){
                minChoice = 1;
            } else{
                minChoice = 2;
            }
        }
    } else if (minDif == 2){
        minChoice = 1;
    } else{
        minChoice = 2;
    }

    // if (minDif == 0){
    //     if (maxDif == 0){
    //         minChoice = 2;
    //     } else{
    //         minChoice = 1;
    //     }
    // }

    cout << minChoice << "\n";
    if (minChoice == 0){
        maxChoice = 0;
    } else{
        maxChoice = maxDif -1;
    }

    cout << maxChoice << "\n";
    return 0;
}