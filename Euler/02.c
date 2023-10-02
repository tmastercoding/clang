#include <stdio.h>

// By considering the terms in the Fibonacci sequence 
// whose values do not exceed four million, 
// find the sum of the even-valued terms.

// get fibbonaci numbers below four million
// get the sum
// get only the even nums


int main(){
    int bef_num = 1;
    int cur_num = 2;
    int sum = 3;
    int max = 4000000;
    
    for (cur_num; ; (!(cur_num &1))? sum+= cur_num: 0 ){
        
        int cur_num_save = cur_num;
        cur_num += bef_num; 
        bef_num = cur_num_save; // before num's val becomes cur_nums val

        if(cur_num > max){
            printf("bef %d\n", bef_num);
            break;
        }

    }

    printf("%d\n", sum);
    
    return 0;
}