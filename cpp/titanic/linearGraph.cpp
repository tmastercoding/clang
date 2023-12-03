#include <iostream>
using namespace std;

class Equation{
    private:
        int mult;
        int add;

    public:
        void setMult(int multInput){
            mult = multInput;
        }
        int getMult(){
            return mult;
        }
        void setAdd(int addInput){
            add = addInput;
        }
        int getAdd(){
            return add;
        }
        void printGraph(int startx, int endx, int starty, int endy, int **calcArr, int size){
            int printed = 0;
            for(int jdx = endy; jdx >= starty; jdx--){
                for(int idx = startx; idx <= endx; idx++){
                    for(int kdx = 0; kdx < size; kdx++){
                        if((calcArr[kdx][0] == idx) && (calcArr[kdx][1] == jdx)){
                            cout << '*';
                            printed = 1;
                        }
                    }
                    
                    if(!printed){
                        if((jdx == 0) && (idx == 0)){
                            cout << '+';
                        } else if(jdx == 0){
                            cout << '-';
                        } else if (idx == 0){
                            cout << '|';
                        } else{
                            cout << '.';
                        }
                    }
                    printed = 0;
                }
                cout << endl;
            }
        }
};


void printCalcArr(int numOfCoor, int** calcArr){
    for(int idx = 0; idx < numOfCoor; idx++){
        for(int jdx = 0; jdx < 2; jdx++){
            cout << calcArr[idx][jdx] << ", ";
        }
        cout << endl;
    }
}
int isNumber(char ch){
    int flag = 0;
    if('0' <= ch && '9' >= ch){
        flag = 1;
    }

    return flag;
}

int pow(int num, int power){
    int ans = 1;
    if(!power){
        ans = 1;
    } else{
        for(int jdx = 0; jdx < power; jdx++){
            ans *= num;
        }
    }

    return ans;
}

int main(){
    cout << "Tay\'s Desmos - Made Using C++" << endl;
    cout << "Please input an equation:" << endl;
    char input[100] = {'\0'}; 
    cin.getline(input, sizeof(input));

    // std::cout << input << endl;
    char temp;
    temp = input[0];
    int isMult = 0;
    int isAdd = 0;
    int add;
    int mult;
    int idx = 1;


    for(; idx < sizeof(input)/sizeof(char); idx++){
        if(input[idx] == 'x'){
            if(isNumber(temp)){
                isMult = 1;
                break;
            } else if(temp == '-'){
                isMult = -1;
                break;
            }
        } else{
            temp = input[idx];
        }
    }



    // cout << isMult << endl;
    if(isMult == 1){
        int count = 0;
        mult = 0;
        for(count = -1; idx >= 0; idx--){
            if(isNumber(input[idx])){
                // cout << count << endl;
                // cout << pow(10, count) << endl;
                mult += (input[idx]-'0') * pow(10, count);
            } else if(input[idx] == '-'){
                mult *= -1;
            }

        }
    } else if (isMult == -1){
        mult = -1;
    } else{
        mult = 1;
    }

    int jdx;
    for(jdx = sizeof(input)/sizeof(char); jdx > 0; jdx--){
        if(input[jdx] == '+'){
            isAdd = 1;
            break;
        } else if(input[jdx] == '-'){
            isAdd = -1;
            break;
        } else if(input[jdx] == 'x'){
            break;
        }
    }

    // cout << isAdd << endl;
    if(isAdd){
        int count = 0;
        add = 0;
        // cout << "jdx " << jdx << endl;
        for(int idx = sizeof(input)/sizeof(char); idx > jdx; idx--){
            // cout << idx << endl;
            if(isNumber(input[idx])){
                // cout << "idx " << idx << endl;
                // cout << count << endl;
                // cout << pow(10, count) << endl;
                // cout << "char " << input[idx];
                add += (input[idx]-'0') * pow(10, count);
                count++;
            } 
        }
        add *= isAdd;
    } else{
        add = 0;
    }

    // cout << mult << endl;
    // cout << add << endl;
    Equation graph;
    graph.setAdd(add);
    graph.setMult(mult);

    int start = -10;
    int end = 10;
    int count = 0;
    for(int idx = start; idx <= end; idx++){
        if( (int)((double)mult * (double)idx + add) == ((double)mult * (double)idx + add)){
            count++;
        }
    }
    int** arr;
    arr = (int **)malloc( count * sizeof(int*));
    for(int idx = 0; idx < count; idx++){
        arr[idx] = (int*)malloc(2 * sizeof(int));
    }
    count = 0;
    for(int idx = start; idx <= end; idx++){
        if( (int)((double)mult * (double)idx + add) == ((double)mult * (double)idx + add)){
            arr[count][0] = idx;
            arr[count][1] = mult * idx + add;
            count++;
        }
    }

    // printCalcArr(count, arr);
    graph.printGraph(start, end, start, end, arr, count);

    return 0;
}