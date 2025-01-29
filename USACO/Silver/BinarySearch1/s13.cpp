#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int length, height, h, heights[500001];
    cin >> length >> height;

    for(int i = 0; i < length; i++){
        cin >> h;
        if(i & 1){
            heights[height-h]++;
            heights[height]--;
        }   else{
            heights[0]++;
            heights[h]--;
        }
    }
    int sum = 0;
    for(int i = 0; i < height; i++){
        cout << heights[i] << ' ';
        sum += heights[i];
        heights[i] = sum;
    }
    cout << '\n';
    int min = 200000, minCnt = 0;
    for(int i = 0; i < height; i++){
        if(heights[i] < min){
            min = heights[i];
            minCnt = 1;
        } else if(heights[i] == min){
            minCnt++;
        }
    }   
    cout << min << ' ' << minCnt << '\n';
    return 0;
}