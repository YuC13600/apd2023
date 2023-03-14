#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> cache;

long long calculate(long long x) {
    long long sum = 0;
    vector<long long> result;
    while (x != 1 && cache.find(x) == cache.end()) {
        result.push_back(x);
        if(x % 2 == 0) {
            x /= 2;
        } else {
            x = 3*x + 1;
        }
    }
    
    sum += cache[x];

    for(long long i = result.size() - 1; i >= 0; --i) {
            sum += result[i];
            cache[result[i]] = sum;
    }
    return sum;
}

int main(void) {
    cache[1] = 1;
    long long n;
    cin >> n;
    while(n--) {
        long long lower_bound, upper_bound;
        cin >> lower_bound >> upper_bound;
        long long max_sum(0), max(0);
        for(long long i = lower_bound; i <= upper_bound; ++i) {
            if(calculate(i) > max_sum) {
                max_sum = calculate(i);
                max = i;
            }
        }
        cout << max_sum << " " << max << endl;
    }
}