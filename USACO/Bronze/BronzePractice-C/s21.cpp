// Angry Cows 11977
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int main(){
    int size;
    cin >> size;
    vector<int> bales, copy, cur, prev;
    vector<int>::iterator iter;
    int temp;
    for(int idx = 0; idx < size; idx++){
        cin >> temp;
        bales.push_back(temp); 
    }
    sort(bales.begin(), bales.end());

    int base = 5;
    int time = 1;
    
    for(int idx = 0; idx < size; idx++){
        base = bales[idx];
        cur.clear();
        time = 1;
        copy = bales;
        copy.erase(find(copy.begin(), copy.end()), base);
        for(int pos = base-time; pos < base+time+1; pos++){
            if(pos == base){
                continue;
            }
            if(find(copy.begin(), begin.end(), pos) != copy.end()){
                cur.push_back(pos);
            }

        }
        // remove
        for(int num: cur){
            copy.erase(find(copy.begin(), copy.end(), num));
        }
        time++;
        prev = cur;
        cur.clear();

        for(int jdx = 0; jdx < prev.size(); jdx++){
            base = prev[jdx];
            for(int pos = base-time; pos < base+time+1; pos++){
                if(pos == base){
                    continue;
                }
                if(find(copy.begin(), begin.end(), pos) != copy.end()){
                    cur.push_back(pos);
                }

            }

        }
    }
    return 0;
}