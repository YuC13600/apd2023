#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, int> cache;

int calculate(int x) {
    int sum = 0;
    vector<int> result;
    while (x != 1 && cache.find(x) == cache.end()) {
        result.push_back(x);
        if(x % 2 == 0) {
            x /= 2;
        } else {
            x = 3*x + 1;
        }

        if(x<1) {
            return 0;
        }
    }
    
    sum += cache[x];

    for(int i = result.size() - 1; i >= 0; --i) {
            sum += result[i];
            cache[result[i]] = sum;
    }
    return sum;
}

int main(void) {
    cache[1] = 1;
    int n;
    cin >> n;
    while(n--) {
        int lower_bound, upper_bound;
        cin >> lower_bound >> upper_bound;
        int max_sum(0), max(0);
        for(int i = lower_bound; i <= upper_bound; ++i) {
            if(calculate(i) > max_sum) {
                max_sum = calculate(i);
                max = i;
            }
        }
        cout << max_sum << " " << max << endl;
    }
}