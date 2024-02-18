#include <iostream>
#include <string>
#include <map>
using namespace std;

/**
 * @date 24.01.07
 * @author Tay Oh
 * @details a program that uses map to 
 *          find the difference between the average male
 *          and female salaries
*/

/*
Input Specification
K (int), the number of currencies used in the datasets, excluding HKD
The next K lines start with the 3 character code for a currency 
followed by a float value for how much it would cost to buy 1 HKD with it
N (int), the number of salaries in the male dataset as well as the female dataset.
The next N lines are the salaries (int) for men. The salary is followed by the currency used
After this, the next N lines are the salaries (int) for women. The salary is followed by the currency used

Output
The difference between between the average male and female salaries rounded to the nearest integer

Example case
Input:
1
EUR 0.1
3
2000 HKD
3000 HKD
500 EUR
400 EUR
2500 HKD
2000 HKD

Output:
500
*/

void inputSal(int noOfSal, map<int, string>& salMap);
int getSumOfSal(map<int, string>& salMap, map<string, double>& curMap);

int main(){
    // get input for the number of currency needed
    int noOfCur = 0;
    cin >> noOfCur;

    // map that takes pair of string, double, stores currenceis
    map<string, double> curMap;
    // inserts default HKD currency
    curMap.insert( pair< string, double >("HKD", 1) );

    // gets input for curMap and inserts
    while( ( curMap.size()-1 ) != noOfCur ){
        string tempStr;
        double tempDouble;
        cin >> tempStr >> tempDouble;
        curMap.insert( pair<string, double>(tempStr, tempDouble));
    }

    // auto print function, prints all pairs
    // cout << "Currencies: " << endl;
    // auto printCur = [](pair<string, double> p) {cout << p.first << ' ' << p.second << endl;};
    // for_each(curMap.begin(), curMap.end(), printCur);

    // number of Salaries
    int noOfSal = 0;
    cin >> noOfSal;

    // map for both male and female salaries
    map<int, string> fSal, mSal;
    
    // get input and insert for fSal
    inputSal(noOfSal, fSal);

    // get input and insert mSal
    inputSal(noOfSal, mSal);

    // print map to check input correct
    // auto printSal = [](pair<int, string> p) {cout << p.first << ' ' << p.second << endl;};
    // for_each(fSal.begin(), fSal.end(), printSal);
    // for_each(mSal.begin(), mSal.end(), printSal);

    // get sum of salary in hkd
    int fSum = getSumOfSal(fSal, curMap);
    int mSum = getSumOfSal(mSal, curMap);
    
    // print difference of fAvg and mAvg
    if((fSum/noOfSal - mSum/noOfSal) >= 0){
        cout << (fSum/noOfSal - mSum/noOfSal) << endl;
    } else{
        cout << (mSum/noOfSal - fSum/noOfSal) << endl;
    }

    return 0;
}

void inputSal(int noOfSal, map<int, string>& salMap){
    // while Map's size is not equal to number of Sal needed
    while((salMap.size()) != noOfSal){
        int tempInt;
        string tempStr;
        // get inpuit
        cin >> tempInt >> tempStr;
        salMap[tempInt] = tempStr;
        // cout << "size " << salMap.size() << endl;
    }
}

int getSumOfSal(map<int, string>& salMap, map<string, double>& curMap){
    int sum = 0;
    // loop map
    for( map<int, string>::iterator it = salMap.begin(); it != salMap.end(); it++){
        // cout << it->first << ' ' << curMap.find(it->second) << endl;
        
        // add the wage of salMap converted to HKD to sum
        sum += int((double)(it->first) / curMap[it->second]);
    }
    return sum;
}