// 색종이 2563
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int size = 0;
    int x = 0, y = 0;
    int arr[100][100] = {0, };
    int cnt = 0;
    // vector<vector<int>> colour;

    cin >> size; 
    for(int idx = 0; idx < size; idx++){
        // temp.clear();
        cin >> x >> y;
        for(int idx = x; idx < x+10; idx++){
            for(int jdx = y; jdx < y+10; jdx++){
                arr[idx][jdx] = 1;
            }
        }
        // temp.push_back(x);
        // temp.push_back(y);
        // colour.push_back(temp);
    }

    for(int x = 0; x <100; x++){
        for(int y = 0; y < 100; y++){
            // cout << arr[x][y] << ' ';
            if(arr[x][y] == 1){
                cnt++;
            }
        }
        // cout << '\n';
    }
        
    //         for(int idx = 0; idx < size; idx++){
    //             if (colour[idx] <= x)
    //         }
    //     }
    // }
    cout << cnt << endl;
    return 0;
}