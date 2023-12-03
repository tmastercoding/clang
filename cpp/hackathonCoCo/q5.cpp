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
using namespace std;

struct Currency{
    string name;
    double costOfHKD;
};

int main(){
    int numOfCur;
    cin >> numOfCur;
    int 
    return 0;
}