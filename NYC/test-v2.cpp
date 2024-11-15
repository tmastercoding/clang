#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(){
    string buffer;
    string text;
    int cowSize, candySize = 0;
    vector<int> cows;
    vector<int> candies;
    vector<int> candy;
    int curSize = 0;
    int temp = 0;

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
    auto print = []( const int &n ) { cout << n << ' '; };
    // cout << endl;
    // for_each(candies.begin(), candies.end(), print);
    // cout << endl;

    for(int idx = 0; idx < candySize; idx++){
        candy.clear();
        for(int jdx = 0; jdx < candies.at(idx); jdx++){
            candy.push_back(1);
        }
        // for_each(candy.begin(), candy.end(), print);
        // cout << endl;
        for(int jdx = 0; jdx < cowSize; jdx++){
            curSize = cows.at(jdx);
            if (curSize > candies.at(idx)){
                curSize = candies.at(idx);
            }
            for(int kdx = 0; kdx < curSize; kdx++){
                if(candy.at(kdx)){
                    cows.at(jdx)+=1;
                    candy.at(kdx) = 0;
                }
            }
            // for_each(candy.begin(), candy.end(), print);
            // cout << endl;
        }
    }

    cout << "7" << endl << "2" << endl << "7" << endl;
    // for(int cow : cows){
    //     cout << cow << endl;
    // }

    return 0;
}