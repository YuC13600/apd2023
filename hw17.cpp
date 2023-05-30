#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while(cin >> n >> m) {
        int ans(n), *arr = new int[n];
        for(int i(0); i < n; ++i) {
            arr[i] = i;
        }
        for(int i(0); i < m; ++i) {
            int a, b;
            cin >> a >> b;
            if(arr[a] != arr[b]) {
                ans--;
                int temp = arr[b];
                for(int j(0); j < n; ++j) {
                    if(arr[j] == temp) {
                        arr[j] = arr[a];
                    }
                }
            }
        }
        cout << ans << '\n';
        delete [] arr;
    }
    return 0;
}
