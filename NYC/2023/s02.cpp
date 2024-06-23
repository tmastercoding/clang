#include <iostream>
#include <string>
#include <vector>
using namespace std;

void input_size(int* size);

int main(){
    // declare variables
    vector<string> jobs;
    vector<string>::iterator iter;
    
    string buffer;

    int tot_jobs = 0;
    int user_size = 0;

    int idx = 0;
    int count = 0;

    // input tot_jobs
    input_size(&tot_jobs);

    // input jobs
    while(idx < tot_jobs){
        getline(cin, buffer);
        jobs.push_back(buffer);
        idx++;
    }

    auto print = [](string job) {cout << job << endl;};
    // for_each(jobs.begin(), jobs.end(), print);

    // input user_size
    input_size(&user_size);

    idx = 0;
    count = tot_jobs;
    // input jobs for user
    while(idx < user_size){
        getline(cin, buffer);
        
        // cmp with existing jobs
        iter = jobs.begin();
        while(iter < jobs.end()){
            if( !(buffer.compare(*iter)) ){
                jobs.erase(iter);
                count--;
            }
            
            iter++;
        }
        idx++;
    }

    // output
    cout << count << endl;
    for_each(jobs.begin(), jobs.end(), print);    

    return 0;
}

void input_size(int* size){
    string buffer;

    while(true){
        getline(cin, buffer);
        *(size) = stoi(buffer);

        // limit
        if((0 < *(size)) && (*(size) < 151)){
            break;
        }

        cout << "Please input integer between 1 and 150" << endl;
    }
}