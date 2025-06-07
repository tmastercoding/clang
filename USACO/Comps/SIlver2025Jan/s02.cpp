#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t = 0;
    cin >> t;
    for(int j = 0; j < t; j++){

        int n;
        long long m, arr[200000], x[600000];
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        // sort(arr, arr+n);
        for(int i = 0; i < n; i++){
            x[i] = arr[i]%m;
        }
        for(int i = n; i < n*2; i++){
            x[i] = x[i-n]+m;
        }
        for(int i = n*2; i < n*3; i++){
            x[i] = x[i-n]+m;
        }

        sort(x, x+n*3);

        long long left = -1, right = -1;
        long long sum = 0, val, prev = x[n];
        // for(int i = 0; i < n*3; i++){
            // cout << x[i] << ' ';
        // }
        // cout << '\n';
        for(int i = 0; i < n*3; i++){
            val = abs(x[i]-x[n]);
            if(left == -1){
                if(x[n]-x[i] > m/2){
                    continue;
                } else{
                    left = i;
                }
            } else{
                if(x[i]-x[n] > (m-1)/2){
                    break;
                } else{
                    right = i;
                }
            }
            // if(val > m/2)
            // cout << val << '\n';
            sum+=val;
        }
        // cout << left <<' ' << right << '\n';
        long long minSum = sum;
        // cout << sum << '\n';
        for(long long i = n+1; i < n*2; i++){
            sum += abs(i-left)*abs(x[i]-prev);
            sum -= abs(right-i+1)*abs(x[i]-prev);
            while(true){
                if(x[i] - x[left] > m/2){
                    sum -= x[i]-x[left];
                    left++;
                } else{
                    break;
                }
            }
            right++;
            while(true){
                if(x[right] - x[i] > (m-1)/2){
                    break;
                } else{
                    sum += x[right]-x[i];
                    right++;
                }
            }
            right--;
            // cout << sum << '\n';
            if(sum < minSum) minSum = sum;
            prev = x[i];
        }
        cout << minSum << '\n';
    }

    
    return 0;
}