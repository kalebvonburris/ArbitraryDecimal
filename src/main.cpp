#include <string>
#include <vector>
#include <iostream>
#include "ArbitraryDecimal.h"

using namespace std;

int main() {

    vector<int> n = {1,0,24};
    vector<int> d = {1,0,32};

    ArbitraryDecimal ad{n, d, 1};

    int a = 24;
    int b = 32;

    ad.simplifyFraction(a, b);

    cout << a << " " << b << endl;

}