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
    int eatSize = 0;
    int temp = 0;
    int dif = 0;

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
    // auto print = []( const int &n ) { cout << n << ' '; };
    // for_each(cows.begin(), cows.end(), print);
    // cout << endl;
    // for_each(candies.begin(), candies.end(), print);
    // cout << endl;

    for(int idx = 0; idx < candySize; idx++){
        eatSize = 0;
        for(int jdx = 0; jdx < cowSize; jdx++){
            // cout << candies.at(idx) << " "<< cows.at(jdx) << endl;
                // dif = candies.at(idx) - cows.at(jdx);
                // cout << dif << " " << eatSize << endl;
            
            if (candies.at(idx) >= cows.at(jdx)){
                if (cows.at(jdx) > eatSize){
                    temp = cows.at(jdx);
                    cows.at(jdx) += cows.at(jdx)-eatSize;
                    eatSize = temp;
                }
            } else if(candies.at(idx) < cows.at(jdx)){
                cows.at(jdx) += candies.at(idx)-eatSize;
                eatSize = candies.at(idx);
            }
            // for_each(cows.begin(), cows.end(), print);
            // cout << endl;
        }
    }
    // for(int idx = 0; idx < candySize; idx++){
    //     eatSize = 0;
    //     for(int jdx = 0; jdx < cowSize; jdx++){
    //         if(eatSize > candies.at(idx)){
    //             break;
    //         } 
    //         if ((eatSize - candies.at(idx)) == 0){
    //             break;
    //         }
    //         if (cows.at(jdx) > eatSize){
    //             if(cows.at(jdx) <= candies.at(idx)){
    //                 temp = cows.at(jdx);
    //                 cows.at(jdx) += cows.at(jdx) - eatSize;
    //                 eatSize = temp;
    //             } else{
    //                 eatSize = candies.at(idx);
    //                 cows.at(jdx) += candies.at(idx);
    //             }
    //         }
    //         // for_each(cows.begin(), cows.end(), print);
    //         // cout << endl;
    //     }
    // }

    for(int cow : cows){
        cout << cow << endl;
    }

    return 0;
}