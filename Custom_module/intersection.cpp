#include <vector>
#include <algorithm>
#include <iostream>

using namespace std ;

/**
 * @date ??.??.??
 * @author Tay Oh
 * @details code using set_intersection()
 *          to show how intersections can be
 *          derived
*/

a, b, c

intersection = getIntersection( a, b )
intersection = getIntersection( intersection, c )

vector<int> getIntersection( vector<int> a, vector<int> b ) {
    vector<int> intersection;

    set_intersection(
        a.begin(), a.end(),
        b.begin(), b.end(),
        back_inserter(intersection)
    );
    return intersection;
};


vector<int> getIntersection( vector<int> a, vector<int> b, vector<int> c ) {
    vector<int> intersection_first;
    vector<int> intersection_end;

    set_intersection(
        a.begin(), a.end(),
        b.begin(), b.end(),
        back_inserter(intersection_first)
    );
    set_intersection(
        intersection_first.begin(), intersection_first.end(),
        c.begin(), c.end(),
        back_inserter(intersection_end)
    );
    return intersection_end;
};

vector<int> getIntersection_1( vector<int> a, vector<int> b, vector<int> c ) {
    vector<int> intersection_first;
    vector<int> intersection_end;

    // sort by asc

    // - vector a

    // - vector b

    // - vector c

    // 비교 할때는 
    // 각 배열의 길이가 있는데,
    // 가장 배열의 길이가 긴 애가 기준이다.
    // ㄱㅏㅈㅏㅇ ㄱㅣㄴ ㅇㅐㄹㅏㅇ ㄱㅏㅈㅏㅇ ㅉㅏㄹㅂㅇㅡㄴ ㅇㅐㄹㅡㄹ ㅁㅓㄴㅈㅣ ㅎㅏㅈㅏ

    for(int v1:  a) {
        
        for(int v2:  b) {
            if (v1 == v2) {
                inter_first.push_back();
            }
        }
    }
    for(int v1:  inter_first) {
        
        for(int v2:  b) {
            if (v1 == v2) {
                inter_end.push_back();
            }
        }
    }
    return intersection_end;
};

int main()  {

    vector<int> p1 {0, 6, 8};
    vector<int> p2 {0, 1, 2, 6, 8};
    vector<int> p3 {0, 1, 6, 8, 9};

    vector<int> intersection;

    // auto print = [](const int &n){ cout << n << endl;};
    // for_each(intersection.begin(), intersection.end(), print);

    for( int n : intersection) {
        cout << n << endl;
    }

    return 0;
}