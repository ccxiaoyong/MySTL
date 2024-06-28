#include <iostream>
#include "syvector.hpp"

#include <vector>
using namespace std;
int main() {
    vector<int> v;
    syvector<int> syv(6,6);
    for(int i = 0; i < 6; ++i){
        syv.push_back(i);
        cout << syv.capacity() << " " << syv[i] << endl;
    }
    return 0;
}