#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> getInterRecur_01( vector<vector<int>>& comb, int idx);


vector<int> recursiveIntersection(vector<vector<int>> comb) {
    auto print = [](const int &n){ cout << n << " ";};
    // cout << "-------------" << endl;
    // for (vector<int>temp: comb){
    //     for_each(temp.begin(), temp.end(), print);
    //     cout << endl;
    // }
    if (comb.size() == 0) {
        return {};
    } else if( comb.size() == 1) {
        return comb[0];
    } else {
        vector<int> intersection = comb[0];
        sort(intersection.begin(), intersection.end());

        comb.erase(comb.begin());
        
        vector<int> tempIntersection;
        vector<int> nextIntersection = recursiveIntersection(comb);

        cout << "temp: ";
        for_each(tempIntersection.begin(), tempIntersection.end(), print);
        cout << endl << "next: ";
        for_each(nextIntersection.begin(), nextIntersection.end(), print);
        cout << endl;

        set_intersection(
            intersection.begin(), intersection.end(),
            nextIntersection.begin(), nextIntersection.end(),
            back_inserter(tempIntersection)
        );
         return tempIntersection;
    }

}

void test() {
    auto print = [](const int &n){ cout << n << endl;};
    vector<vector<int>> comb {{1, 9, 3}, {9, 6, 3}};

    vector<int> intersection = comb[0];
    vector<int> nextIntersection = comb[1];

    sort(intersection.begin(), intersection.end());
    for_each(intersection.begin(), intersection.end(), print);
    sort(nextIntersection.begin(), nextIntersection.end());
    for_each(nextIntersection.begin(),nextIntersection.end(), print);

    vector<int> tempIntersection;

    set_intersection(
        intersection.begin(), intersection.end(),
        nextIntersection.begin(), nextIntersection.end(),
        back_inserter(tempIntersection)
    );

    cout << "Intersection: ";
    for( int n : tempIntersection ) {
        cout << n << " ";
    }
    cout << endl;
}

int main(){
    // [ 1, 2, 3  ]
    // [ 3, 5, 7  ]
    // [ 1, 9, 3  ]
    // [ 9, 6, 3  ]
    vector<vector<int>> comb {{1, 2, 3}, {3, 5, 7}, {1, 9, 3}, {9, 6, 3}};

    auto print = [](const int &n){ cout << n << endl;};
    vector<int> inter;

    set_intersection(
        comb[2].begin(), comb[2].end(),
        comb[3].begin(), comb[3].end(),
        back_inserter(inter)
    );
    vector<int> intersection = recursiveIntersection(comb);

    // test();
    for_each(inter.begin(), inter.end(), print);
    return 0;
}

// return intersection

vector<int> getInterRecur_01( vector<vector<int>>& comb, int idx) {
    vector< int> tmp;

    if( comb.empty() ) {
        return {};
    } else if( comb.size() == 1) {
        return comb[0];
    } else {
        vector<int> intersection = getInterRecur_01( comb, idx + 1);

        // get intersection
        set_intersection(
            comb[0].begin(), comb[0].end(),
            intersection.begin(), intersection.end(),
            back_inserter(tmp)
        );
    }

    return tmp;
};