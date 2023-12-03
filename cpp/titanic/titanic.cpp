#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    // read file
    FILE *f;
    ifstream f("./titanic.csv", "r");

    // sort file into 3d array using malloc
    string buffer;

    while(getline(f, buffer)){
        cout << buffer;
        buffer = "\0";
    }
    // output file

    fclose(f);

    return 0;
}