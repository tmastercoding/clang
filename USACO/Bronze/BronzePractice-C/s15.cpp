// Back and Forth 16771
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(){
    int tank1 = 1000, tank2 = 1000;
    int tueTank1, tueTank2;
    int wedTank1, wedTank2;
    int thuTank1, thuTank2;
    int friTank1, friTank2;
    vector<int> buckets1, buckets2;
    vector<int> tueBuckets1, tueBuckets2;
    vector<int> wedBuckets1, wedBuckets2;
    vector<int> thuBuckets1, thuBuckets2;
    vector<int>::iterator iter1, iter2, iter3, iter4;
    set<int> possible;
    int temp;
  
    for(int idx = 0; idx < 10; idx++){
        cin >> temp;
        buckets1.push_back(temp);
    }
    for(int idx = 0; idx < 10; idx++){
        cin >> temp;
        buckets2.push_back(temp);
    }

    // Tuesday
    for(iter1 = buckets1.begin(); iter1 != buckets1.end(); iter1++){
        tueBuckets1 = buckets1;
        tueBuckets2 = buckets2;
        tueTank1 = tank1;
        tueTank2 = tank2;

        tueTank1 -= *iter1;
        tueTank2 += *iter1;
        tueBuckets1.erase(tueBuckets1.begin()+(iter1-buckets1.begin()));
        tueBuckets2.push_back(*iter1);

        // Wednesday
        for(iter2 = tueBuckets2.begin(); iter2 != tueBuckets2.end(); iter2++){
            wedBuckets1 = tueBuckets1;
            wedBuckets2 = tueBuckets2;
            wedTank1 = tueTank1;
            wedTank2 = tueTank2;

            wedTank2 -= *iter2;
            wedTank1 += *iter2;
            wedBuckets2.erase(wedBuckets2.begin()+(iter2-tueBuckets2.begin()));
            wedBuckets1.push_back(*iter2);

            // Thursday
            for(iter3 = wedBuckets1.begin(); iter3 != wedBuckets1.end(); iter3++){
                thuBuckets1 = wedBuckets1;
                thuBuckets2 = wedBuckets2;
                thuTank1 = wedTank1;
                thuTank2 = wedTank2;

                thuTank1 -= *iter3;
                thuTank2 += *iter3;
                thuBuckets1.erase(thuBuckets1.begin()+(iter3-wedBuckets1.begin()));
                thuBuckets2.push_back(*iter3);

                // Friday
                for(iter4 = thuBuckets2.begin(); iter4 != thuBuckets2.end(); iter4++){
                    friTank1 = thuTank1;
                    friTank2 = thuTank2;
                    friTank2 -= *iter4;
                    friTank1 += *iter4;
                    possible.insert(friTank1);
                }
            }
        }
    }

    cout << possible.size() << '\n';

    return 0;
}