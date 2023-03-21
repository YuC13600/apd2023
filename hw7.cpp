#include <iostream>
using namespace std;

int main(void) {
    int n;
    char c, buffer[1024];
    cin >> n;
    while(cin.get() != '\n');
    // cout << n << endl;
    while(n--) {
        int score[101] = {0};
        int in = 0, maxx = 0;
        do {
            cin >> in;
            score[in]++;
            maxx = max(maxx, in);
        } while(cin.get() != '\n');
        int ans = 0, shift = (maxx >= 95 ? 0 : 95 - maxx);
        // cout << shift << endl;
        for(int i=55-shift; i<60-shift; ++i) {
            ans += score[i];
            // cout << score[i] << endl;
        }
        cout << ans << endl;
    }
}