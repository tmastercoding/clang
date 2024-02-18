#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * @date 23.01.07
 * @author Tay Oh
 * @details A program using vector, that 
 *          prints the fewest amounts of coins that 
 *          can be used.
*/

/*
Input Specifications:
N, the number of coins in the set of denominations
K, the target value
A list of N integers separated by a space, each available coin

Output Specifications:
The integer value of the fewest amount of coins that could be used
There are no other restrictions on the values. 

Example Case 1:
Input:
3
16
10 5 1

Output:
3

Example Case 2:
Input:
4
30
20 12 6 1

Output:
3
*/
int main(){
    int noOfTypes = 0;
    cin >> noOfTypes;
    int totalNeeded = 10;
    cin >> totalNeeded;

    // vector of types of coins
    vector<int> coinTypes;
    
    // input for types of coins
    char buffer[100];
    char* p_buffer = buffer;
    char ch;
    fflush(stdin);
    while((ch = getchar() ) != '\n'){
        *(p_buffer++) = ch;
    }
    *(p_buffer) = '\0';
    string strInput(buffer);
    // size of string
    int strSize = strInput.length()+1;
    // seperator
    char sep[] = " ";
    
    // create character array of strInput
    char* cstr = new char[ strSize ];
    strcpy(cstr, strInput.c_str());
    
    // splits the char array with strtok 
    // inputs each number turned to an int
    // into coinTypes vector
    char* p = strtok(cstr, sep);
    while(p != 0){
        coinTypes.push_back(stoi(p));
        p = strtok( NULL, sep);
    }

    // minimum coins
    int minCoins = 0;
    // current coin count
    int count = 0;

    // iter set at coinTypes' start
    vector<int>::iterator iter = coinTypes.begin();
    
    // loops the coinTypes starting at different positions
    for(int start = 0; start < noOfTypes; start++){
        // temporary total val
        int tempTotal = totalNeeded;
        count = 0;
        // iter begins at begin() + start
        for(iter = coinTypes.begin()+start; iter!= coinTypes.end(); iter++){
            // count is how many *iters can fit into tempTotal
            count += (int)(tempTotal / *iter);
            // tempTotal is the remainder of tempTotal/*iter
            tempTotal %= *iter;
        }
        // if tempTotal is 0 and (start is 0 or count is smaller than minCoins)
        if((!tempTotal) && ((start == 0) || (minCoins>count))){
            // mincoins is count
            minCoins = count;
        }
    }

    cout << minCoins << endl;
    return 0;
}