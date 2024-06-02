#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

void cpp_ver();
void c_ver();

int main(){
    // cpp_ver();
    c_ver();
    return 0;
}

void cpp_ver(){
    int size, num;
    // get input
    while(1){
        cin >> size >> num;

        // check range
        if ((1 <= size )&& (num >= 10000)){
            break;
        }
        // error message
        cout << "Please make size greater or equal to 1 and num smaller or equal to 10000" << endl;
    }

    // create vector
    vector<int> numbers;

    // get input for numbers
    int temp = 0;

    /// add temp to vector
    for(int idx = 0; idx < size-1; idx++){
        cin >> temp;
        numbers.push_back(temp);
    }

    // int* p_num = &num;
    // auto smallerThan = []( const int &n, const int &num ) {if(n < num) cout << n << ' ';};
    // for_each(numbers.begin(), numbers.end(), smallerThan(num = p_num))

    // if iter smaller than num, print iter
    vector<int>::iterator iter = numbers.begin();
    for(; iter != numbers.end(); iter++){
        if(*iter < num) cout << *iter << ' ';  
    }
    cout << endl;
}

void c_ver(){
    int size, num;
    // input size num
    scanf("%d %d", &size, &num);
    fflush(stdin);

    // malloc numbers
    int* numbers = (int* )malloc(size * sizeof(int));
    
    int idx = 0;
    // input numbers
    while(idx < size){
        scanf("%d", &(numbers[idx++]));
    }
    
    idx = 0;
    // loop through numbers
    while(idx < size){
        // if less than
        if(num > numbers[idx]){
            // output
            printf("%d ", numbers[idx]);
        }
        idx++;
    }

    printf("\n");
}