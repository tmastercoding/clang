/*

Problem Statement
In an effort to curb emissions and promote sustainable development,
the UN has just created a new currency called Carbon Coins. 
All countries have been given a set amount based on their population
and are required to give back one coin per
ten million metric tons of carbon dioxide equivalents they produce. 

Your country wants to maximise the number of coins they have at the end of any transaction, 
so that your president could fill a bathtub with them should he so choose. 
As the lowly secretary, you have been tasked with finding the fewest amount of coins 
needed to exactly match the transaction value, K. 

Unfortunately for you, it seems like the UN changes the denominations of the coins constantly
as they try to find the set that works the best. 
This means that you’ll have to start all of your calculations from scratch each time. 

There will always be a $1 coin, and each denomination will be a distinct integer value.

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

Explanation:
In this case, it is optimal to use one of each of the three coins, as they add to 16. 


*/

#include <iostream>
using namespace std;

int strToInt(char* str, int length);

void split(int* dest, int dest_size, char* src, int src_size, int sep);

void str_cpy(char* dest, int dest_size, char* src, int src_size);

int main(){
    int numOfTypes = 0;
    cin >> numOfTypes;
    int* typesArr = (int* )malloc(sizeof(int) * numOfTypes);


    int targetValue = 0;
    cin >> targetValue;
    
    char str[100] = {'\0', };
    char* pStr = str;
    char ch;

    fflush(stdin);
    while((ch = getchar()) != '\n'){
        *(pStr++) = ch;
    }
    *(pStr++) = '\n';

    // cout << str;

    split(typesArr, numOfTypes, str, sizeof(str), ' ');
    // int count = 0;
    // int minCount = 0;
    // int tempTarget = targetValue;
    
    // for(int start = 0; start < numOfTypes; start++){
    //     count = 0;
    //     tempTarget = targetValue;
    //     for(int idx = start; idx < numOfTypes; idx++){
    //         count += tempTarget / typesArr[idx];
    //         tempTarget %= typesArr[idx];
    //     }
    //     if(count < minCount){
    //         minCount = count;
    //     } else if(start == 0){
    //         minCount = count;
    //     }
    // }
    
    free(typesArr);
    return 0;
}

int strToInt(char* str, int length){
    int num = 0;
    int exponent = 0;
    int multiply = 1;

    int end = length -1;
    while(str[end] == '\0'){
        end--;
    }

    for(int idx = end; idx > -1; idx--){
        multiply = 1;   
        for(int jdx = 0; jdx < exponent; jdx++){
            multiply *= 10;
        }
        num += (str[idx] - '0') * multiply;
        exponent++;
    }

    return num;
}

void split(int* dest, int dest_size, char* src, int src_size, int sep){
    
    char buffer[10] = {'\0', };
    char* p_buffer = buffer;
    int count = 0;
    char empty[10] = {'\0', };

    // loop going through src
    for(int idx = 0; idx < src_size; idx++){
        // if character is sep or new line
        if((src[idx] == sep) || (src[idx] == '\n') ){
            cout << "Pre: \'"<< buffer << '\'' << endl;   
            
            // assign the buffer to dest[count]
            dest[count] = strToInt(buffer, sizeof(buffer));

            cout << dest[count] << endl;
            // add count by 1
            count++;

            // empty buffer
            str_cpy(buffer, sizeof(buffer), empty, sizeof(empty));
            cout << "Post: "<< buffer << endl;
            p_buffer = buffer;
            continue;
        }
        *(p_buffer++) = src[idx];
    }   

    cout << "count: " << count << endl;
    for(int idx = 0; idx < dest_size; idx++){
        cout << dest[idx] << endl;
    }
    if(count == dest_size){
        break;
    }
}

void str_cpy(char* dest, int dest_size, char* src, int src_size){
    if(dest_size >= src_size){
        for(int idx = 0; idx < src_size; idx++){
            dest[idx] = src[idx];
        } 
        dest[src_size] = '\0';
    } else{
        printf("Size of destination must be greater or equal to size of src\n");
    }
}