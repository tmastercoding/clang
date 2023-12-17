/*
Problem Statement
Good news! After your fine work as a data analyst,
you’ve been promoted to… senior data analyst. How exciting! 
In an effort to impress your bosses after receiving this new role, 
you want to do some analysis on the gender pay gap post COVID-19. 

You have data sets of salaries from men and women with the same job titles.
There’s just one catch… since the boom of remote work, 
many people are working for jobs for companies in foreign countries.
Because of this, some of them are getting paid in foreign currencies. 

With the salaries and conversion rates in hand, 
can you find the difference between the average male
and female salaries?

You are given the conversion rate for every used currency to HKD.

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

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

struct Currency{
    string name;
    double costOfHKD;
};

int getTotWage(int numOfSal, int numOfCur, Currency* curList){
    int tot = 0;
    int wage = 0;
    string currency = "\0";

    for(int idx = 0; idx < numOfSal; idx++){
        wage = 0;
        currency = "\0";    
        cin >> wage >> currency;

        for(int jdx = 0; jdx < numOfCur; jdx++){
            if(!(currency.compare(curList[jdx].name))){
                // cout << curList[jdx].name << endl;
                tot += wage / curList[jdx].costOfHKD ;
            } else if(!(currency.compare("HKD"))){
                // cout << "HKD" << endl;
                tot += wage;
            }
        }
    }

    return tot;
}

int main(){
    int numOfCur = 0;
    cin >> numOfCur;
    Currency *curList = (Currency *)malloc(numOfCur * sizeof(Currency));
    for(int idx = 0; idx < numOfCur; idx++){
        cin >> curList[idx].name >> curList[idx].costOfHKD;
    }
    // for(int idx = 0; idx < numOfCur; idx++){
    //     cout << curList[idx].name << " " << curList[idx].costOfHKD << endl;
    // }

    int numOfSal = 0;
    cin >> numOfSal;
    int wTot = getTotWage(numOfSal, numOfCur, curList);
    int wAvg = wTot/numOfSal;
    // cout << wTot << endl;
    // cout << wAvg << endl;

    int mTot = getTotWage(numOfSal, numOfCur, curList);
    int mAvg = mTot/numOfSal;
    // cout << mTot << endl;
    // cout << mAvg << endl;


    int dif = mAvg - wAvg;
    if(dif < 0){
        dif = 0 - dif;
    }
    cout << dif << endl;
    // for(int idx = 0; idx < numOfCur; idx++){
    //     free(curList[idx]);
    // }
    free(curList);

    return 0;
}