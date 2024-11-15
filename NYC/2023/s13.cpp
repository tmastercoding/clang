#include <iostream>
#include <string>
using namespace std;

int main(){
    int size = 5;
    string text = "()(())(())";
    int cnt = 0;

    // cin >> size;
    // cin >> text;

    for (int idx = 0; idx < size*2-1; idx++){
        cout << text << endl;
        if( ( text[idx] == '(') && (text[idx+1] == ')')){
            cout << idx << endl;
            text.replace(idx, idx+2, "");
            idx -=2;
            cnt++;
        }
        // if( ( text[idx] == ')') && (text[idx+1] == '(')){
        //     text.replace(idx, idx+2, "");
        //     cnt++;
        // }
    }
    cout << text << cnt << endl;
    return 0;
}


// print(text, cnt)
// while text.count('()'):
//     cnt += text.count('()')
//     text = text.replace('()', '')
//     print(text, cnt)


// while len(text):
//     cnt += (text.count(')(') * 2)
//     text = text.replace(')(', '')
//     print(text, cnt)

// print(cnt)
