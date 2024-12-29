#include <iostream>
#include <string>
using namespace std;

int main(){
    int n, f, odx = 0;
    string src, out[700];
    cin >> n >> f;
    cin >> src;

    for(char pre = 'a'; pre <= 'z'; pre++){
        for(char post = 'a'; post <= 'z'; post++){
            if(pre == post){
                continue; 
            }
            int cnt = 0;
            for(int idx = 0; idx < n-2; idx++){
                if(src[idx] == pre && src[idx+1] == post && src[idx+2] == post){
                    cnt++;
                    idx+=2;
                }
            }
            if(cnt >= f){
                string tmp = "";
                tmp += pre;
                tmp += post;
                tmp += post;
                out[odx++] = tmp;
            } else if(cnt == f-1){
                cnt = 0;
                for(int idx = 0; idx < n-2; idx++){
                    if(src[idx] == pre && src[idx+1] == post && src[idx+2] == post){
                        idx+=2;
                    } else if((src[idx+1] == post && src[idx+2] == post) || (src[idx] == pre && src[idx+1] == post) || (src[idx] == pre && src[idx+2] == post)){
                        if(idx < n-3){
                            if(src[idx+1] == pre && src[idx+2] == post && src[idx+3] == post){
                                continue;
                            }
                        }
                        if(idx < n-4){
                            if(src[idx+2] == pre && src[idx+3] == post && src[idx+4] == post){
                                continue;
                            }
                        }
                        cnt=1;
                        break;
                    }
                }
                if(cnt){
                    string tmp = "";
                    tmp += pre;
                    tmp += post;
                    tmp += post;
                    // cout<<tmp;
                    out[odx++] = tmp;
                }
            }
        }
    }
    cout << odx << '\n';
    for(int idx = 0; idx < odx; idx++){
        cout << out[idx] << '\n';
    }
    return 0;
}