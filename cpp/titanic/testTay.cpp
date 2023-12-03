#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {

    ifstream file("./titanic.csv");
    string buffer;
    string head;
    int line_cnt = 0;
    const int buffer_size = 50;

    while( getline( file, buffer ) )  {
        if( !line_cnt ) {
            head = buffer;
        } 
        cout << buffer << endl;
        line_cnt++;
    }

    file.close();
    char ***headArr;
    headArr = (char ***)malloc(line_cnt * sizeof(char **));

    cout << "==== head ====" << endl;
    cout << head << endl;

    int comma_cnt = 2;
    for(int idx = 0; idx < head.length(); idx++){
        if (head[idx] == ','){
            comma_cnt++;
        }
    }


    char** row;
    row = (char**)malloc( comma_cnt * sizeof(char *));

    char line[100] = {'\0', };
    char word_buffer[50] = {'\0',};

    strcpy( line, head.c_str() );
    for (int idx = 0, jdx = 0, cdx = 0; ; idx++){
        if( line[idx] == ',' || line[idx]  == '\0') {
            cout << "==== comma ====" << endl;
            word_buffer[jdx]= '\0';
            jdx = 0;
            row[cdx]= ( char* )malloc( 50 * sizeof(char));
            strcpy(row[cdx], word_buffer);
            cdx++;
            cout << word_buffer << endl;
        } else {
            word_buffer[jdx++] = line[idx];
        }
        if( line[idx] == '\0'){
            break;
        }
    }
    cout << word_buffer << endl;

    for(int idx = 0; idx < comma_cnt-1; idx++){
        cout << row[idx] << endl;
    }

    for(int idx = 0; idx < comma_cnt-1; idx++){
        free(row[idx]);
    } 

    free(row);

    return 0;
}