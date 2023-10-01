#include <stdio.h>

int len(char *str);

int strToNum(char *str);

int power(int num, int times);

int main(int argc, char **argv){

    int pre  = strToNum(argv[1]);
    int post = strToNum(argv[3]);

    printf("pre: %d \npost: %d \n", pre, post);

    char op = argv[2][0];

    switch (op)
    {
    case '+':
        /* code */
        printf("ans: %d\n",  pre + post);
        break;
    
    case '-':
        printf("ans : %d\n", pre - post);
        break;
        
    case '*':
        printf("ans : %d\n", pre * post);
        break;

    case '/':
        printf("ans : %d\n", pre / post);
        break;

    default:
        printf("Please input an operator that is +, -, * or /.\n");
        break;
    }
    
    return 0;
}

int len(char *str){
    int count = 0;

    for(int pos = 0; str[pos] != '\0'; pos++){
        count++;
    }

    return count;
}

int strToNum(char *str){
    int num = 0;

    for(int pos = 0; pos < len(str); pos++){
        // num =  (num + ((str[pos] - '0') * power(10, pos)));
        num = num*10 +  (str[pos] - '0');
        printf( "logs : pos %d, num: %d \n", pos, num);
    }

    return num;
}


int power(int num, int times){
    for(int pos = 0; pos < times-1; pos++){
        num*=num;
    } 

    if (!times){
        num = 1;
    }

    return num;
}