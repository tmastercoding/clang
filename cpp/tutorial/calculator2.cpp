// 10 + 5
// buffer[100]
// split sep ' '
// assign to pre, post, op use by malloc 
// convert string to integer ( double )
// switch as operator
// output 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

class Operation {
    private:
        double preNum;
        char op;
        double postNum;

    public:
        double getPreNum(){
            return this->preNum;
        }

        double getPostNum(){
            return this->postNum;
        }

        char getOp(){
            return this->op;
        }

        void setPreNum(double preNumInput){
            this->preNum = preNumInput;
        }

        void setPostNum(double postNumInput){
            this->postNum = postNumInput;
        }

        void setOp(char opInput){
            this->op = opInput;
        }

        void input(double preNumInput, char opInput, double postNumInput){
            setPreNum(preNumInput);
            setPostNum(postNumInput);
            setOp(opInput);
        }
        
        void printInfo(){
            printf("PreNum : %f\n", getPreNum());
            printf("Operator : %c\n", getOp());
            printf("PostNum : %f\n", getPostNum());
        }
        
        double doCalc(){
            double ans;
            printf("%f %c %f = ", preNum, op, postNum);
            switch(op){
                case '+':
                    ans = preNum + postNum;
                    break;

                case '-':
                    ans = preNum - postNum;
                    break;
                
                case '/':
                    ans = preNum / postNum;
                    break;

                case 'x':
                    ans = preNum * postNum;
                    break;

                case '*':
                    ans = preNum * postNum;
                    break;
            }
            printf("%f\n", ans);
            return ans;
        }
};

int len(char *string);
int split(char *array, char* op, char sep, char* pre, char* post);
void copy(char *location, char *src);
void clear(char *array);
double strToDouble(char *string);

int main(){
    // buffer
    char buffer[100] = {'\0',};

    // get input
    gets(buffer);
    fflush(stdin);

    // arrays for op, pre and post
    char opStr[100] = {'\0',};
    char preStr[100] = {'\0',};
    char postStr[100] = {'\0',};

    // split buffer and put into these strings
    split(buffer, opStr, preStr, postStr);
    
    // convert pre and post to double
    double pre = strToDouble(preStr);
    double post = strToDouble(postStr);
    
    // make the first letter of opStr be op
    char op = opStr[0];

    // create Operation object
    Operation operation;

    // input values into operation
    operation.input(pre,op,post);

    // do the calculation
    operation.doCalc();

    return 0;
}

int len(char *string){
    int size = 0;
    while(*string != '\0'){
        string++;
        size++;
    }

    return size;
}

int split( char *array, char* op, char sep, 
           char* pre, char* post){
    int bufferIdx = 0;
    int arrayPos = 0;
    char buffer[100] = {'\0',};

    for(int idx = 0; idx < 3; idx++){
        bufferIdx = 0;

        while( array[arrayPos] != ' ' ){
            if(array[arrayPos] == '\0'){
                break;
            }
            buffer[bufferIdx] = array[arrayPos];
            bufferIdx++;
            arrayPos++;
        }
        arrayPos++;

        if(idx == 0){
            // char* preTemp = (char * )malloc(sizeof(char) * len(buffer));
            copy(pre, buffer);
        } else if(idx == 1){
            // char* opTemp = (char * )malloc(sizeof(char) * len(buffer));
            copy(op, buffer);
        } else{
            // char* postTemp = (char * )malloc(sizeof(char) * len(buffer));
            copy(post, buffer);
        }
        clear(buffer);
    }


    return 0;
}

void copy(char *location, char *src){
    // if(len(src) != size){
    //     printf("Error");
    //     return;
    // }

    for(int idx = 0; idx < len(src); idx++){
        // printf("src[idx] %c\n", src[idx]);
        location[idx] = src[idx];
    }
}

void clear(char *array){
    while(*array != '\0'){
        *array = '\0';
        array++;
    }
}

double strToDouble(char *string){
    double num = 0;
    int stringLen = len(string) - 1;
    int decimalFlag = 0;
    int startPos = 0;
    int idx;

    // check if string contains decimal point
    for(startPos = 0; startPos < stringLen; startPos++){
        if(string[startPos] == '.'){
            // set decimalFlag to True
            decimalFlag = 1;

            // increase startPos by 1 to skip the decimal point
            startPos++;
            break;
        }
    }  
    
    // if decimalFlag isn't true
    if(!decimalFlag){
        // set startPos to 0
        startPos = 0;

        // loop from the last digit to the first
        for(idx = stringLen; idx >= startPos; idx--){
            int power = (int)pow(10, stringLen - idx);
            char integer = string[idx];
            int stringNum = atoi(&(integer));
            num += power*stringNum;
        }
    } else{
        // printf("DECIMAL\n");
        for(idx = startPos; idx < stringLen+1; idx++){
            // printf("idx: %d\n", idx);
            // printf("string[idx] %c\n", string[idx]);
            int power = (int)pow(10, (idx-startPos) + 1);
            char integer = string[idx];
            // printf("atoi(&(string[idx])): %d\n", atoi(&integer));
            int stringNum = atoi(&(integer));
            // printf("stringNum = %d\n", stringNum);
            // printf("power: %d\n", power);
            // printf("power/stringNum: %f\n", (double)stringNum/power);
            num += (double)stringNum/power;
        }
        int decimalPos = idx - startPos;

        for(int jdx = stringLen-decimalPos-1; jdx >= 0; jdx--){
            int power = (int)pow(10, stringLen - jdx - 1 - decimalPos);
            char integer = string[jdx];
            // printf("atoi(&(string[idx])): %d\n", atoi(&integer));
            int stringNum = atoi(&(integer));
            // printf("stringNum = %d\n", stringNum);
            // printf("power: %d\n", power);
            num += power*stringNum;
        }
    }

    return num;
}