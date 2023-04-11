#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>
#include <iterator>
#include <cmath>
using namespace std;

bool is_prime(int n) {
    if(n == 0 || n == 1) return false;
    for(int i = 2; i <= sqrt(n); ++i) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(void) {

    unsigned n(0);
    while(cin >> n) {
        vector<bool> vec(32, false);
        for(int i=31; i>=0; --i) {
            vec[i] = n%2;
            n /= 2;
        }
        do {
            unsigned cur(0);
            int index = 1;
            for(int i=31; i>=0; --i) {
                cur += vec[i] * index;
                index *= 2;
            }
            if(is_prime(cur)) {
                cout << cur << endl;
                break;
            }
        } while(prev_permutation(vec.begin(), vec.end()));
    }
    // vector<bool> v(32, false);
    // v[0] = true;
    // do {
    //     copy(v.begin(), v.end(), ostream_iterator<bool>(cout, ""));
    //     cout << endl;
    // } while(prev_permutation(v.begin(), v.end()));
    
    return 0;
}
