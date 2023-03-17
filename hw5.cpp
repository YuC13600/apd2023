#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long cache[1000000]={0};

long long calculate(long long x) {
    long long sum = 0;
    vector<long long> result;
    while (x != 1 && ((x > 1000000 || x < 1) || cache[x] == 0)) {
        result.push_back(x);
        if(x % 2 == 0) {
            x /= 2;
        } else {
            x = 3*x + 1;
        }

        if(x < 1) {
            return 0;
        }
    }
    
    sum += cache[x];

    for(long long i = result.size() - 1; i >= 0; --i) {
            sum += result[i];
            if (result[i] < 1000000) {
                cache[result[i]] = sum;
            }
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
    return 0;
}