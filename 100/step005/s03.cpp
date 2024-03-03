#include <iostream>
#include <string>
using namespace std;

int main(){
    int inputTimes = 0;
    vector<string> strArr;
    string temp;

    cin >> inputTimes;

    for(int idx = 0; idx < inputTimes; idx++){
        cin >> temp;
        strArr.push_back(temp);
    }
    
    // vector<string>::iterator it;
    // for(it = strArr.begin(); it < strArr.end(); it++){
    //     cout << (*it)[0] << (*it)[(*it).length()-1]<< endl;
    // }

    auto firstLast = [](const string &text){cout << text[0] << text[text.length()-1] << endl;};
    for_each(strArr.begin(), strArr.end(), firstLast);

    return 0;
}