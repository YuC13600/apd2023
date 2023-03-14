#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Rectangle {
    int width, height;
};

bool cmp(Rectangle a, Rectangle b) {
    return a.width < b.width;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<Rectangle> rectangles(n);
        for (int i = 0; i < n; i++) {
            cin >> rectangles[i].width >> rectangles[i].height;
            if (rectangles[i].width > rectangles[i].height) {
                swap(rectangles[i].width, rectangles[i].height);
            }
        }

        sort(rectangles.begin(), rectangles.end(), cmp);

        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (rectangles[i].width >= rectangles[j].width && rectangles[i].height >= rectangles[j].height) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i]);
        }

        cout << ans << endl;
    }

    return 0;
}
