#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    // times repeated
    int times = 0;

    // index
    int idx = 0;

    // deliminator
    char dlm = '\n';

    // line size
    const int line_size = 30;

    // tokenise variables
    char* buffer;
    char* buffer2;
    char sep[] = " ";


    // input lines
    char line[line_size] = {'\0',};
    vector<pair<int, string>> lines;

    // input times
    cin >> times;
    cin.ignore();

    // input lines
    while(idx < times){
         
        // tokenise
        buffer = strtok(line, sep);
        buffer2 = strtok(NULL, sep);

        // insert as pair
        lines.push_back( pair<int, string>(stoi(buffer), buffer2));
        idx++;
    }

    // auto print = [](pair<int, string> pairs){cout << pairs.first << ' ' << pairs.second << endl;};
    // for_each(lines.begin(), lines.end(), print);
    
    // output
    for(vector<pair<int, string>>:: iterator it = lines.begin(); it != lines.end(); it++){
        for(int idx = 0; idx < it->second.length(); idx++){
            for(int repeat = 0; repeat < it->first; repeat++){
                cout << it->second[idx];
            }
        }
        cout << endl;
    }

    return 0;
}