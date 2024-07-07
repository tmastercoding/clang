#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

/*
* 
    @ author :
        - name  : Tay Oh
        - email : tmastercubing@gmail.com
    @ since : Friday 5th July 2024

    @ function name : binToInt
    @ params : 
        - string data                          : string containing binary
    @ return_value : decimal int of data
    @ desc: |
        gets a binary string, 
        and converts it into
        decimal int

    @ function name : getPossible
    @ params : 
        - string data                          : string containing 
                                                 state of a 7-segment
        - vector<pair<int, string>> segments   : vector of pairs which
                                                 is number: state of 7-segment
        - string mask                          : string of mask that shows
                                                 which segments work
        - string origin_dat                    : string to compare mask to

    @ return_value : vector of possible values
    @ desc: |
        gets data and mask,
        to get possible numbers
        data could represent
        returns with vector

    @ function name : getInterRecur
    @ params : 
        - vector<vector<int>> comb             : combination of vectors of
                                                 states of 7-segments
        - vector<int>* returnVal               : vector of intersections between
                                                 all terms of comb

    @ return_value : 0, just exits the func
    @ desc: |
        gets comb and returnVal,
        recurs function to get intersection
        of all terms in comb
        returns indirectly through
        returnVal
*/

// binToInt func
int binToInt(string data);

// getPossible
vector<int> getPossible(string data, vector<pair<int, string>> segments, string mask, string origin_data);

// getInterRecur
int getInterRecur( vector<vector<int>> comb, vector<int>* returnVal);

int main(){
    // declare varibales
    string buffer;
    string temp;
    vector<string> mask;
    
    // assign segments
    vector<pair<int, string>> segments = 
    {
    {0, "1111110"},
    {1, "0110000"},    
    {2, "1101101"},
    {3, "1111001"},
    {4, "0110011"},
    {5, "1011011"},
    {6, "1011111"},
    {7, "1110000"},
    {8, "1111111"},
    {9, "1111011"},
    };

    int key;
    string value;
    string pre, post;

    vector<vector<int>> postComb;
    vector<int> prePoss;
    vector<int> postPoss;
    vector<int> postInter;
    vector<int> output;
    vector <int>::iterator it;
    int maxPost;
    int num;
    bool isMatch = false;

    // auto func to print
    auto print = [](const int &n){ cout << n << endl;};
    
    // test print segments
    vector<pair<int, string>>::iterator iter = segments.begin();
    // for(;iter != segments.end(); iter++){

    //     key = iter->first;
    //     value = iter->second;
    //     cout << key << ":" << value << endl;
    // }

    int caseSizes = 0;

    // get mask
    getline(cin, buffer);
    istringstream iss(buffer);
    iss >> temp;
    mask.push_back(temp);
    iss >> temp;
    mask.push_back(temp);

    // get case size
    getline(cin, buffer);
    caseSizes = stoi(buffer);
    
    // get cases
    for(int idx = 0; idx < caseSizes; idx++){
        getline(cin, buffer);
        istringstream iss(buffer);
        iss >> pre;
        iss >> post;

        // getPossible for pre + poss
        prePoss = getPossible(pre, segments, mask.at(0), "1111111");
        postPoss = getPossible(post, segments, mask.at(1), "1111111");

        // for_each(prePoss.begin(), prePoss.end(), print);
        // for_each(postPoss.begin(), postPoss.end(), print);

        // add vector to vector
        postComb.push_back(postPoss);
    }

    // for_each(prePoss.begin(), prePoss.end(), print);
    // cout << "post" << endl;

    // for(vector<int>temp: postComb){
    //     for_each(temp.begin(), temp.end(), print);
    //     cout << "----------" << endl;
    // }

    /*
     * @TITLE : get intersection 
     * @DESC : of post terms
    */

    if(caseSizes>1){
        // get intersections
        getInterRecur(postComb, &postInter);
        // get max
        maxPost = *max_element(postInter.begin(), postInter.end());
    
    // if size of first > 1
    } else if(postComb.at(0).size()){
        maxPost = postComb.at(0).at(0);
    } else{
        maxPost = 0;
    }

    // get output vec
    for(it = prePoss.begin() ;it != prePoss.end(); it++){
        num = (*it)*10 + maxPost;
        if(num > 0){
            output.push_back(num);
        }
    }

    // print size
    cout << output.size() << endl;
    if(output.size()){
        // print terms
        for(it = output.begin() ;it != output.end(); it++){
            cout << *it << " ";
        }
        cout << endl;
    }
    
    // if(prePoss.size()>0){
    //     it = tempPoss.begin();
    //     intersect=*it;
    //     for(; it != tempPoss.end() ; it++){
    //         for(int ival: intersect){
    //             isMatch = false;
    //             for(int pval: *it){
    //                 if(ival == pval){
    //                     isMatch = true;
    //                     break;
    //                 }
    //             }
    //             if(!isMatch){
    //                 intersect.erase(ival)
    //             }
    //         }
    //     }        
    // }

    return 0;
}

int binToInt(string data){
    return stoi(data, nullptr, 2);
}

vector<int> getPossible(string data, vector<pair<int, string>> segments, string mask, string origin_data){
    vector<int> possible;
    bool isWorking = false;
    int count = 0;
    int maskVal;
    int dec_cur_segment;
    int dec_data;
    int dec_mask;
    vector<pair<int, string>>::iterator iter = segments.begin();

    if(!mask.compare(origin_data)){
        isWorking = true;
    }
    // cout << "isWorking: " << isWorking << endl;

    for(; iter != segments.end(); iter++){
        dec_cur_segment = binToInt(iter->second);
        dec_data = binToInt(data);
        dec_mask = binToInt(mask);

        // cout << "segment: " << dec_cur_segment << endl;
        // cout << "data: " << dec_data << endl;
        // cout << "mask: " << dec_mask << endl;

        if(!isWorking){
            maskVal = dec_cur_segment & dec_data;
            if(maskVal == dec_data){
                possible.push_back(iter->first);
            }
        } else{
            maskVal = dec_mask & dec_data;
            if(maskVal == dec_cur_segment){
                possible.push_back(iter->first);
            } 
        }
    }
    
    return possible;
}

int getInterRecur( vector<vector<int>> comb, vector<int>* returnVal) {
    vector<int> inter;

    // get intersection
    set_intersection(
        comb.at(0).begin(), comb.at(0).end(),
        comb.at(1).begin(), comb.at(1).end(),
        back_inserter(inter)
    );

    // erase 0th term 
    comb.erase(comb.begin());
    // assign 1st (now 0)
    comb.at(0).assign(inter.begin(), inter.end());
    returnVal->assign(inter.begin(), inter.end());


    if(comb.size() > 1){
        getInterRecur(comb, returnVal);
    } 

    return 0;
};