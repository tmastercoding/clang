/*
* titile:
* - Calculating Caloric Intake
*
* You are designing a system that can distribute 
*   food equally amongst people in a region depending 
*   on their activity level and BMR (Basal metabolic rate)
*
There are 4 activity levels, light, moderate, high and extra.
To calculate the caloric intake, you multiply the BMR by
the according value for each activity level. 
1.375 for light,
1.55 for moderate, 
1.725 for high and 
1.9 for extra.

first input:
Your first input value is an integer C that 
represents how many calories you have to distribute.
second input:
Your second input value is an integer N that 
represents the number of people you need to distribute amongst.
third input:
This will then be followed by a string list A with length N 
that represents the activity level for each person. 
last input:
The last input will be a float list B with length N 
that represents the BMR for each person in the 
same order as the list A.

job output:
Your job is to output the remainder calories 
as a whole number rounded down multiplied by the 
average caloric intake as a whole number rounded down.

*/

#include <iostream>
#include <string>
using namespace std;

/*
test 1:
5000
2
moderate
high
50
50
*/

struct Person{
    int calNeed;
    string activityLevel;
    int bmr;

};

void getInput(int* variable){
    while(1){
        cin >> *variable;
        if (*variable < 0){
            cin >> *variable;
            cout << "Please enter an integer greater than 0" << endl;
        } else{
            break;
        }
    }

}

int main(){
    
    int cal = 5000;
    int number = 2;
    // getInput(&cal);
    // getInput(&number);
    cin >> cal;
    cin >> number;

    // cout << cal << endl;
    // cout << number << endl;

    int sum = 0;
    int avg;

    Person *p = (Person *)malloc(sizeof(Person) * number);

    for(int idx = 0; idx < number; idx++){
       cin >> p[idx].activityLevel;
    //    cout << p[idx].activityLevel << endl;
    }
    for(int idx = 0; idx < number; idx++){
        cin >> p[idx].bmr;
        // cout << p[idx].bmr << endl;
        if( !(p[idx].activityLevel.compare("light"))) {
            p[idx].calNeed = p[idx].bmr * 1.375;
        } else if(!(p[idx].activityLevel.compare("moderate"))) {
            p[idx].calNeed = p[idx].bmr * 1.55;
        } else if(!(p[idx].activityLevel.compare("high"))) {
            p[idx].calNeed = p[idx].bmr * 1.725;
        } else if( !(p[idx].activityLevel.compare("extra"))) {
            p[idx].calNeed = p[idx].bmr * 1.9;
        } 
        // cout << p[idx].calNeed << endl;

        sum += p[idx].calNeed;
        cal -= p[idx].calNeed;
    }

    avg = sum/number;

    cout << avg * cal << endl;
    return 0;
}