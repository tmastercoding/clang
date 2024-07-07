#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> getIntersection( vector<int> a, vector<int> b ) {
    vector<int> intersection;

    set_intersection(
        a.begin(), a.end(),
        b.begin(), b.end(),
        back_inserter(intersection)
    );
    return intersection;
};

int getInterRecur( vector<vector<int>> comb, vector<int>* returnVal) {
    vector<int> inter;

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

int main(){
    vector<int> a {1, 6, 8};
    vector<int> b {0,1,3,4,5,6,7,8,9};
    vector<int> c {6, 8};
    vector<int> d {6};
    vector<vector<int>> comb;

    vector<int> intersection;

    auto print = [](const int &n){ cout << n << endl;};

    // for_each(a.begin(), a.end(), print);
    
    // individual
    // intersection = getIntersection(a, b);
    // for_each(intersection.begin(), intersection.end(), print);

    // intersection = getIntersection(intersection, c);
    // for_each(intersection.begin(), intersection.end(), print);

    comb.push_back(a);
    comb.push_back(b);
    comb.push_back(c);
    comb.push_back(d);

    getInterRecur(comb, &intersection);
    for_each(intersection.begin(), intersection.end(), print);


    return 0;
}