#include <iostream>
#include <vector>
#include <algorithm> // for std::set_intersection
#include <iterator>  // for std::back_inserter

using namespace std;

int idx = 0;

vector<int> recursiveIntersection(vector<vector<int>> comb) {
    if (comb.empty()) {
        return {};
    } else if( comb.size() == 1) {
        sort(comb[0].begin(), comb[0].end());
        return comb[0];
    } else {
        vector<int> intersection = comb[0];

        sort( intersection.begin(), intersection.end());

        comb.erase(comb.begin());

        cout << idx <<  " : Vector elements: ";
        for (const auto& elem : intersection) {
            cout << elem << " ";
        }
        cout << endl;

        vector<int> tempIntersection;
        vector<int> nextIntersection = recursiveIntersection(comb);

        cout << idx << " : nextIntersection elements: ";
        for (const auto& elem : nextIntersection) {
            cout << elem << " ";

        }
        idx++;
        cout << endl;

        set_intersection(
            intersection.begin(), intersection.end(),
            nextIntersection.begin(), nextIntersection.end(),
            back_inserter(tempIntersection)
        );

        return tempIntersection;
    }

}

int main() {
    vector<vector<int>> comb {{1, 2, 3}, {3, 5, 7}, {1, 9, 3}, {9, 6, 3}};

    auto print = [](const int &n){ cout << n << " "; };

    // 첫 번째 인덱스부터 재귀 함수를 호출하여 교집합을 계산합니다.
    vector<int> intersection = recursiveIntersection(comb);

    cout << "Intersection: ";
    for( int n : intersection ) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
