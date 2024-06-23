#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main(){
    // declare variables
    int width = 0;
    int line_size = 0;
    int idx = 0;
    int jdx = 0;
    int state = 0;
    int count = 0;
    int isMatch = 0;
    int isSkip = 0;
    int temp = 0;
    
    string buffer;
    string prev;
    string cur;
    string tempLine;

    vector<string> tags {"<CENTER>", "</CENTER>", "<RIGHT>", "</RIGHT>"};
    vector<string> lines;
    vector<string>::iterator iter;

    // get input fo width + line_size
    getline(cin, buffer);
    istringstream iss(buffer);
    iss >> tempLine;
    line_size = stoi(tempLine);
    iss >> tempLine;
    width = stoi(tempLine);


    while(idx < line_size){
        // cout << idx << endl;
        getline(cin, buffer);
        jdx = 0;

        // split
        count = 1;
        for(char ch: buffer){
            if(ch == ' '){
                count++;
            }
        }
        // cout << count << endl;
        
        // cout << "buffer: " << buffer << endl;
        istringstream iss(buffer);
        iss >> prev;
        jdx = 1;
        isSkip = 0;

        tempLine.clear();
        if (count == 1){
            lines.push_back(prev);
        } else{
            while(jdx <= count){
                iss >> cur;

                if( (prev.size() + 1 + cur.size()) <= width ){
                    if(!isSkip && count != jdx){
                        tempLine.assign(prev);
                        tempLine.append("-");
                        tempLine.append(cur);

                        if((tempLine.size() < width) && (jdx < count-1)){
                            prev.assign(tempLine);
                            jdx++;
                            continue;
                        } else{
                            prev.clear();
                        }

                        lines.push_back(tempLine);
                        isSkip = 1;
                        
                    } else if(count == jdx && !isSkip){
                        lines.push_back(cur);
                    } else {
                        prev.assign(cur);
                        isSkip = 0;
                    }
                } else{
                    tempLine.assign(prev);
                    lines.push_back(tempLine);
                    prev.assign(cur);
                }

                // cout << "jdx: " << jdx << endl;
                // cout << "templine: "<< tempLine << endl;
                jdx++;
            }
        }

        // cout << "Lines so far:" << endl;
        // for(string line: lines){
        //     cout << line << endl;
        // }


        idx++;
    }

    cout << "FINISH " << endl;

    // output
    iter = lines.begin();
    for(;iter < lines.end(); iter++){
        // get state
        isMatch = 0;
        jdx = 0;
        for(string tag: tags){
            if(!tag.compare(*iter)){
                switch(jdx){
                    case 0:
                        state = 1;
                        isMatch = 1;
                        break;

                    case 1:
                        state = 0;
                        isMatch = 1;
                        break;

                    case 2:
                        state = 2;
                        isMatch = 1;
                        break;

                    case 3:
                        state = 0;
                        isMatch = 1;
                        break;
                }
            }
            jdx++;
        }
        if(isMatch){
            continue;
        }
        tempLine.clear();
        temp = (*iter).size();
        switch(state){
            case 0:
                tempLine.assign(*iter);
                for(int kdx = 0; kdx < width - temp; kdx++){
                    tempLine.append("-");
                }
                break;
            case 1:
                for(int kdx = 0; kdx < (int)((width - temp)/2); kdx++){
                    tempLine.append("-");
                }
                tempLine.append(*iter);
                temp = tempLine.size();
                for(int kdx = 0; kdx < width - temp; kdx++){
                    tempLine.append("-");
                }
                break;
            case 2:
                for(int kdx = 0; kdx < (width - temp); kdx++){
                    tempLine.append("-");
                }
                tempLine.append(*iter);
            
                break;
        }

        // cout << "state: " << state << endl;
        cout << tempLine << endl;
    }
    return 0;
}