#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
const unsigned TABLE_SIZE = 1000000;

bool is_prime(unsigned n) {
    if(n == 0 || n == 1) return false;
    for(int i = 2; i <= sqrt(n); ++i) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

void eratosthenes(bool *table, unsigned n) {
    for(unsigned i = 0; i <= n; i++) {
        table[i] = true;
    }
    table[0] = table[1] = 0;
    for(unsigned i = 2; i <= n; i++) {
        if(table[i]) {
            if(1ll * i * i <= n) {
                for(unsigned j = i * i; j <= n; j += i) {
                    table[j] = 0;
                }
            }
        }
    }
}

unsigned count_ones(int n) {
    unsigned count = 0;
    while(n) {
        if(n & 1) count++;
        n >>= 1;
    }
    return count;
}

unsigned find_sbn_prime(unsigned p, bool *table) {
    unsigned ones_count = count_ones(p);
    for(unsigned q = p; q >= 2; --q) {
        if(p < TABLE_SIZE) {
            if(table[q] && ones_count == count_ones(q)) {
                return q;
            }
        } else {
            if(is_prime(q) && ones_count == count_ones(q)) {
                return q;
            }
        }
        
    }
    return 0;
}

int main() {
    unsigned int p;
    bool *table = new bool[TABLE_SIZE+1];
    eratosthenes(table, TABLE_SIZE);
    while(cin >> p) {
        unsigned sbn_prime = find_sbn_prime(p, table);
        cout << sbn_prime << endl;
    }
    return 0;
}
