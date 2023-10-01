#include <iostream>
#include <fstream>
using namespace std;

int main(){
    // Create and open text file
    // ofstream = ouput file stream
    ofstream MyFile("filename.txt");
    
    // Write to the file
    MyFile << "Files can be tricky, but it is fun enough!";

    // Close the file
    MyFile.close();

    // read from the text file
    // ifstream = input file stream
    ifstream MyReadFile("filename.txt");

    // create buffer
    string myText;

    // put each line of filename.txt to myText
    while (getline (MyReadFile, myText)){
        // print myText
        cout << myText;
    }

    // close the file
    MyReadFile.close();
}