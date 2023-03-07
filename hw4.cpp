#include <iostream>
using namespace std;
const int MAX = 100000000;
int main(void) {
    int m;
    cin >> m;
    int **arr = new int*[m];
    for(int i=0; i<m; ++i)
        arr[i] = new int[m];

    for(int i=0; i<m; ++i)
        for(int j=0; j<m; ++j)
            cin >> arr[i][j];

    int t1(MAX);
    for(int i=0; i<m-1; ++i) {
        for(int j=1; j<m-1; ++j) {
            int cur = arr[i][j] + arr[i][j-1] + arr[i][j+1] + arr[i+1][j];
            t1 = min(t1, cur);
        }
    }
    int t2(MAX);
    for(int i=1; i<m; ++i) {
        for(int j=1; j<m-1; ++j) {
            int cur = arr[i][j] + arr[i-1][j] + arr[i][j-1] + arr[i][j+1];
            t2 = min(t2, cur);
        }
    }
    int t3(MAX);
    for(int i=1; i<m-1; ++i) {
        for(int j=0; j<m-1; ++j) {
            int cur = arr[i][j] + arr[i-1][j] + arr[i+1][j] + arr[i][j+1];
            t3 = min(t3, cur);
        }
    }
    int t4(MAX);
    for(int i=1; i<m-1; ++i) {
        for(int j=1; j<m; ++j) {
            int cur = arr[i][j] + arr[i][j-1] + arr[i-1][j] + arr[i+1][j];
            t4 = min(t4, cur);
        }
    }
    cout << min(min(t1, t2), min(t3, t4));
    return 0;
}