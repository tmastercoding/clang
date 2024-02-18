#include <iostream>
#include <string>
#include <vector>
using namespace std;

// int maxItem()

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

    int v_max_value = *max_element( scores.begin(), scores.end());
    int v_max_index = max_element( scores.begin(), scores.end()) - scores.begin();
    
    cout << v_max_value << ' ' << v_max_index << endl;
    
    vector<int>::iterator iter;
    for( iter = scores.begin() ; iter != scores.end(); ++iter )

    for(int score: scores){
        total += (float)score/v_max_value*100;
    }

    avg = total/count;

    cout << avg << endl;

    return 0;
}