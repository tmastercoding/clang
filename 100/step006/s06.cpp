#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    // get input
    string target;
    getline(cin, target);

    // list of croat alphabet
    vector<string> croat { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
    // int croat_size = croat.size(); // vector use iter 
    int size = target.size();
    // count of char
    int count = 0;
    int jdx = 0;
    // flag showing match
    bool isFoundMatch = false;

    // loop through string 
    while(jdx < size){
        // iter for croat
        vector<string>::iterator iter = croat.begin();

        // loop through croat letters
        for(; iter != croat.end(); iter++){
            
            // compare letters
            for(int idx = 0; idx < (*iter).size(); idx++){
                
                if((*iter).at(idx) == target.at(jdx+idx)){
                    // if found match
                    if(idx == (*iter).size()-1){
                        // flag is true
                        jdx += idx;
                        count++;
                        isFoundMatch = true;
                        break;
                    }
                } else{
                    break;
                }
            }        
        }

        // if no match add count
        if(!isFoundMatch){
            count++;
        }
        isFoundMatch = false;
        jdx++;
    }
    // output
    cout << count << endl;

    return 0;
}