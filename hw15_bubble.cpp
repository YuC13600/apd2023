#include <iostream>
using namespace std;

int main(void) {
    long long n, w_sum(0);
    cin >> n;
    long long *w, *f;
    w = new long long[n];
    f = new long long[n];
    for(int i(0); i < n; ++i) {
        cin >> w[i];
        w_sum += w[i];
    }
    for(int i(0); i < n; ++i) {
        cin >> f[i];
    }
    for(int i(n-1); i > 0; --i) {
        for(int j(0); j < i; ++j) {
            if(f[j] * w[j+1] > f[j+1] * w[j]) {
                swap(w[j], w[j+1]);
                swap(f[j], f[j+1]);
            } 
        }
    }
    long long ans(0);
    for(int i(0); i < n; ++i) {
        w_sum -= w[i];
        ans += f[i] * w_sum;
    }
    cout << ans << endl;
}
