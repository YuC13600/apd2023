#include <iostream>
#include <cmath>
using namespace std;

int table[4][16]={
    {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
    {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
    {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
    {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
};

int main(void) {
    char input[7];
    while(scanf("%s", input)!=EOF) {
        int r = 2*(input[0]-48) + (input[5]-48);
        int c(0);
        for(int i=0; i<4; ++i) {
            c += (input[4-i] - 48) * pow(2, i);
        }
        int ans = table[r][c];
        char output[5];
        for(int i=3; i>=0; --i) {
            output[i] = ans%2 + 48;
            ans /=2;
        }
        output[4] = '\0';
        cout << output << endl;
    }
    return 0;
}