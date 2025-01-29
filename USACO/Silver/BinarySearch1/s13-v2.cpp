#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int length, height, h, lheights[500001], uheights[500001], heights[500001];
    cin >> length >> height;

    for(int i = 0; i < length; i++){
        cin >> h;
        if(i & 1){
            uheights[height-h]++;
            uheights[height]--;
        }   else{
            lheights[0]++;
            lheights[h]--;
        }
    }
    int sum = 0;
    for(int i = 0; i < height; i++){
        sum += lheights[i];
        heights[i] = sum;
    }
    sum = 0;
    for(int i = 0; i < height; i++){
        sum += uheights[i];
        heights[i] += sum;
    }
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