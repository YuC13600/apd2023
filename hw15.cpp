#include <iostream>
#include <vector>
using namespace std;
#define INT_MAX_REDIFINED 2147483647
#define INT_MIN_REDIFINED -2147483648

int main(void) {
    int n, input_buffer;
    cin >> n;
    vector<int> w, f;
    for(int i(0); i<n; ++i) {
        cin >> input_buffer;
        w.push_back(input_buffer);
    }
    for(int i(0); i<n; ++i) {
        cin >> input_buffer;
        f.push_back(input_buffer);
    }
    int w_sum(0);
    for(int i(0); i<n; ++i) {
        w_sum += w[i];
    }
    int ans(0);
    for(int i(0); i<n; ++i) {
        int min_val(INT_MAX_REDIFINED), min_idx(-1);
        for(int j(0); j<w.size(); ++j) {
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