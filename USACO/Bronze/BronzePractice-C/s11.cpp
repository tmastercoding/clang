// Out of Place 15594
#include <iostream>
using namespace std;

// int isAsc(int* arr, int size);

int main(){
    int size;
    cin >> size;
    int heights[size];
    int temp;
    int outIdx;
    int cnt = 0;

    for(int idx =0 ; idx < size; idx++){
        cin >> temp;
        heights[idx] = temp;
    }


    int prev;
    prev = heights[0];
    for(int idx = 1; idx < size; idx++){
        if(heights[idx] < prev){
            outIdx = idx;
            break;
        }
        prev = heights[idx];
    }    
    cout << outIdx << endl;
    
    return 0;
}
// int isAsc(int* arr, int size){
//     int prev = arr[0];
//     for(int idx = 1; idx < size; idx++){
//         if (arr[idx] < prev){
//             return 0;
//         }
//         prev = arr[idx];
//     }
//     return 1;
// }