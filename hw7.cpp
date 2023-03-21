#include <iostream>
using namespace std;

int main(void) {
    int n;
    char c, buffer[1024];
    scanf("%d%*c", &n);
    // cout << n << endl;
    while(n--) {
        int score[101];
        for(int i=0; i<101; ++i)
            score[i] = 0;
        int in = 0, maxx = 0;
        scanf("%[^\n]%*c", buffer);
        // cout << buffer << endl;
        char *ptr = buffer;
        while(*ptr != '\0') {
            if(*ptr != ' ') {
                in = in*10 + (*ptr - '0');
            } else {
                score[in]++;
                // cout << in << endl;
                maxx = max(maxx, in);
                in = 0;
            }
            ptr++;
        }
        score[in]++;
        // cout << in << endl;
        maxx = max(maxx, in);
        // cout << maxx << endl;
        // cout << "cross" << endl;
        int ans = 0, shift = (maxx >= 95 ? 0 : 95 - maxx);
        // cout << shift << endl;
        for(int i=55-shift; i<60-shift; ++i) {
            ans += score[i];
            // cout << score[i] << endl;
        }
        cout << ans << endl;
    }
}