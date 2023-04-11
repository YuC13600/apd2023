#include <algorithm>
#include <iostream>
#include <vector>
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
        if(n == 0 || n == 1) {
            cout << 0 << endl;
            continue;
        }
        vector<bool> vec(32, false);
        for(int i=31; i>=0; --i) {
            vec[i] = n%2;
            n /= 2;
        }
        bool flag(true);
        do {
            unsigned cur(0);
            int index = 1;
            for(int i=31; i>=0; --i) {
                cur += vec[i] * index;
                index *= 2;
            }
            if(is_prime(cur)) {
                cout << cur << endl;
                flag = false;
                break;
            }
        } while(prev_permutation(vec.begin(), vec.end()));
        if(flag) {
            cout << 0 << endl;
        }
    }
    return 0;
}
