#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main(){
    string buffer;
    const int size = 20;
    int idx = 0;
    double total = 0.0;
    double total_of_mark = 0.0;
    char sep = ' ';
    int jdx = 0;
    string token;
    double mark = 0.0;
    double grade = 0.0;

    while(idx < size){
        getline(cin, buffer);
        stringstream sstream(buffer);
        jdx = 0;
        while(getline(sstream, token, sep)){
            if(jdx == 1){
                mark = atof(token.c_str());
            } else if(jdx == 2){
                grade = 0;
                switch(token.at(0)){
                    case 'A':
                        grade = (token.at(1) == '+')? 4.5: 4.0;
                        break;
                    case 'B':
                        grade = (token.at(1) == '+')? 3.5: 3.0;
                        break;
                    case 'C':
                        grade = (token.at(1) == '+')? 2.5: 2.0;
                        break;
                    case 'D':
                        grade = (token.at(1) == '+')? 1.5: 1.0;
                        break;
                    case 'P':
                        mark = 0.0;
                        break;
                    default:
                        break;
                };
            }
            jdx++;
        }

        total += (mark * grade);
        total_of_mark += mark;
      
        idx++;
    }

    cout << total/total_of_mark << endl;
    return 0;
}