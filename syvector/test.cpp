#include <iostream>
#include "syvector.hpp"

#include <vector>
using namespace std;
int main() {
    vector<int> v;
    syvector<int> syv(6,6);
    // syv.push_back(2);
    // syv.push_back(3);
    // syv.push_back(4);
    // syv.push_back(5);
    // syv.push_back(6);

    for(int i = 0; i < 6; ++i){
        // syv.push_back(i);
        cout << syv.capacity() << " " << syv[i] << endl;
    }
    return 0;
}