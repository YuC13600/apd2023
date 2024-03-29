#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--) {
        int score[101] = {0};
        int in = 0, max_score = 0;
        do {
            cin >> in;
            score[in]++;
            max_score = max(max_score, in);
        } while(cin.get() == ' ');
        int ans = 0, shift = (max_score >= 95 ? 0 : 95 - max_score);
        //cout << max_score << endl << shift << endl;
        for(int i=55-shift; i<60-shift; ++i) {
            if(i >= 0 && i <= 100)
                ans += score[i];
        }
        cout << ans << '\n';
    }
}