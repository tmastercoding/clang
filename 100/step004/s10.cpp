#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int count = 3;
    const int size = 100;
    char buffer[ size ];
    char sep[] = " ";
    float total = 0;
    float avg = 0;
    vector<int> scores;
    int idx = 0;
    
    // cin.getline(char buf[], int size, char delimitChar)
    cin.getline( buffer, size, '\n' );

    // cout << buffer << endl;

    char* p = strtok(buffer, sep);
    while(p != NULL){
        scores.push_back(stoi(p));
        p = strtok(NULL, sep);
    }

    for(int val: scores){
        cout << val << endl;
    }

    int v_max_value = *max_element( scores.begin(), scores.end());
    int v_max_index = max_element( scores.begin(), scores.end()) - scores.begin();
    
    cout << v_max_value << ' ' << v_max_index << endl;

    // auto calc = [](int &n, int v_max_value){(float)n/v_max_value*100;};
    vector<int>::iterator iter;
    // for_each(scores.begin(), scores.end(), calc);

    for( iter = scores.begin() ; iter != scores.end(); iter++){
        total += (float)(*iter)/v_max_value*100;
    }

    // for(int score: scores){
    //     total += (float)score/v_max_value*100;
    // }

    avg = total/count;

    cout << avg << endl;

    return 0;
}