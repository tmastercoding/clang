#include <iostream>
#include <string>
using namespace std;

int main(){
    string buffer;
    int size = 0;
    int time = 0;

    do{
        getline(cin, buffer);
        size = buffer.size();
        if(size > 15 || size < 2){
            cout << "Please input text from 2-15" << endl;
        } else{
            for(char ch: buffer){
                time += (ch-'A')/3 + 3;
            }

            cout << time << endl;
            break;
        }
        
    } while( 1 );
    

    return 0;
}