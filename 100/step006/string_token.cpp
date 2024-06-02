#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    string line = "Tokenizing a string with stringstream";

    vector<string> words;
    stringstream sstream(line);
    string word;

    while(getline(sstream, word, ' '))
    {
        words.push_back(word);
    }

    for (int i=0; i<words.size(); i++)
        cout << words[i] << endl;

    return 0;
}