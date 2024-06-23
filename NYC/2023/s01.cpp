#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int get_dir(vector<vector<int>> town, int x, int y, int size, int reach, int addToX, int addToY);
int get_x(vector<vector<int>> town, int x, int y, int size, int reach);
int get_plus(vector<vector<int>> town, int x, int y, int size, int reach);

int main(){
    int size = 0;
    int reach = 0;

    
    vector<vector<int>> town;
    string buffer;
    getline(cin, buffer);
    istringstream iss(buffer);
    iss >> size;
    iss >> reach;

    string temp;

    for(int idx = 0; idx < size; idx++){
        vector<int> row;
        getline(cin, buffer);
        istringstream iss(buffer);
        while(iss >> temp){
            row.push_back(stoi(temp));
        }
        town.push_back(row);
    }

    int max = 0;
    int tempX = 0;
    int tempPlus = 0;
    for(int idx = 0; idx < size; idx++){
        for(int jdx = 0; jdx < size; jdx++){
            tempX = get_x(town, idx, jdx, size, reach);
            tempPlus = get_plus(town, idx, jdx, size, reach);

            if(tempX > max){
                max = tempX;
            }
            
            if(tempPlus > max){
                max = tempPlus;
            }
        }
    }
    cout << max << endl;
    return 0;
}


int get_dir(vector<vector<int>> town, int x, int y, int size, int reach, int addToX, int addToY){
    int tot = 0;
    int count = 0;

    while(1){
        x += addToX;
        y += addToY;
        
        if (!((0 <= x) && (x < size))){
            break;
        }
        if (!((0 <= y) && (y < size))){
            break;
        }

        if (!(count < reach)){
            break;
        }
        // printf("%d %d\n", x, y);
        count++;

        tot += town.at(x).at(y);
    }

    return tot;
}

int get_x(vector<vector<int>> town, int x, int y, int size, int reach){
    return get_dir(town, x, y, size, reach, 1, 1) \
    + get_dir(town, x, y, size, reach, 1, -1)     \
    + get_dir(town, x, y, size, reach, -1, -1)    \
    + get_dir(town, x, y, size, reach, -1, 1)  \
    + town.at(x).at(y);
}

int get_plus(vector<vector<int>> town, int x, int y, int size, int reach){
    return get_dir(town, x, y, size, reach, 1, 0) \
    + get_dir(town, x, y, size, reach, -1, 0)     \
    + get_dir(town, x, y, size, reach, 0, -1)    \
    + get_dir(town, x, y, size, reach, 0, 1)  \
    + town.at(x).at(y);
}