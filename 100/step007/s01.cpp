#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

/*
* 
    @ author :
        - name  : Tay Oh
        - email : tmastercubing@gmail.com
    @ since : Sunday 1st June 2024
    @ function name : add_matrix
    @ params : 
        - vector<vector<int>> &matrix     : stores values in nested vector matrix
        - int size_of_row                 : row numbers in matrix
        - int size_of_col                 : col numbers in matrix
        - int isSet                       : 1 if init, 0 if adding to existing
    @ return_value : none
    @ desc: |
        gets a 2D vector, 
        and inputs/adds to according to
        flag
*/

void add_matrix(vector<vector<int>> &matrix, int size_of_row, int size_of_col, int isSet);

int main(){
    // declare variables
    int size_of_row = 3;
    int size_of_col = 3;
    
    // int idx, jdx = 0;
    // int count = 0;
    // string buffer;
    // string sep = " ";
    // string temp;

    // construct matrix secondary vector
    vector<vector<int>> matrix;

    // add to matrix
    add_matrix(matrix, size_of_row, size_of_col, 1);
    add_matrix(matrix, size_of_row, size_of_col, 0);

    // view matrix
    auto print_row = [](int& n){cout << n << " ";};

    for(vector<int> row: matrix){
        for_each(row.begin(), row.end(), print_row);
        cout << endl;
    }
    return 0;

    // vector<int> row;
    // for(idx = 0;idx < size_of_row; idx++){
    //     row.clear();
    //     getline(cin, buffer);
    //     // cout << buffer << endl;

    //     istringstream iss(buffer);
    //     while(iss >> temp){
    //         if(!temp.empty()){
    //             row.push_back(stoi(temp));
    //         }
    //     }
    //     matrix.push_back(row);
    // }

    // for(idx = 0;idx < size_of_row; idx++){
    //     row.clear();
    //     getline(cin, buffer);
        
    //     count = 0;
    //     istringstream iss(buffer);
    //     while(iss >> temp){
    //         if((!temp.empty())){
    //             row.push_back(matrix.at(idx).at(count) + stoi(temp));
    //         }
    //         count++;
    //     }
    //     matrix.at(idx).swap(row);
    // }
}


void add_matrix(vector<vector<int>> &matrix, int size_of_row, int size_of_col, int isSet){
    // vector row
    vector<int> row;

    // variable for getline (input)
    string buffer;
    string sep = " ";
    string temp;

    // count for col
    int count = 0;

    // loop for rows
    for(int idx = 0; idx < size_of_row; idx++){
        // clear row
        row.clear();
        // input
        getline(cin, buffer);
        
        count = 0;
        
        // create a stream for buffer  
        istringstream iss(buffer);

        while(iss >> temp){
            // if temp is not temp
            if((!temp.empty())){
                // if inputting
                if(isSet){
                    // add temp to row
                    row.push_back(stoi(temp));
                } else{
                    // add current value to prev value
                    row.push_back(matrix.at(idx).at(count) + stoi(temp));
                }
            }
            count++;
        }
        // if inputting
        if(isSet){
            // add row to matrix
            matrix.push_back(row);
        } else{
            // or swap row
            matrix.at(idx).swap(row);
        }
    }
}