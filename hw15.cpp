#include <iostream>
#include <vector>
using namespace std;
#define INT_MAX_REDIFINED 0xffffffffffffffff

int main(void) {
    unsigned long long n, input_buffer;
    cin >> n;
    vector<unsigned long long> w, f;
    for(unsigned long long i(0); i<n; ++i) {
        cin >> input_buffer;
        w.push_back(input_buffer);
    }
    for(unsigned long long i(0); i<n; ++i) {
        cin >> input_buffer;
        f.push_back(input_buffer);
    }
    unsigned long long w_sum(0);
    for(unsigned long long i(0); i<n; ++i) {
        w_sum += w[i];
    }
    unsigned long long ans(0);
    for(unsigned long long i(0); i<n; ++i) {
        unsigned long long min_val(INT_MAX_REDIFINED), min_idx(0);
        for(unsigned long long j(0); j<w.size(); ++j) {
            if(min_val > f[j] * (w_sum - w[j])) {
                min_val = f[j] * (w_sum - w[j]);
                min_idx = j;
            }
        }
        ans += min_val;
        w_sum -= w[min_idx];
        w.erase(w.begin() + min_idx);
        f.erase(f.begin() + min_idx);
    }
    cout << ans << endl;
}