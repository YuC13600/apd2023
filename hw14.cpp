#include <iostream>
#define INT_MAX_REDIFINED 2147483647
#define INT_MIN_REDIFINED -2147483648
using namespace std;

int main(void) {
    int n;
    cin >> n;
    while(n--) {
        int m;
        cin >> m;
        int *arr = new int[m];
        for(int i(0); i<m; ++i) {
            cin >> arr[i];
        }
        int **dp_max = new int*[m];
        for(int i(0); i<m; ++i) {
            dp_max[i] = new int[m];
        }
        for(int i(0); i<m; ++i) {
            dp_max[i][i] = 0;
            dp_max[i][i+1] = 0;
        }
        int **dp_min = new int*[m];
        for(int i(0); i<m; ++i) {
            dp_min[i] = new int[m];
        }
        for(int i(0); i<m; ++i) {
            dp_min[i][i] = 0;
            dp_min[i][i+1] = 0;
        }
        for(int i(2); i<m; ++i) {
            for(int j(0); j<m-i; ++j) {
                int max_val(INT_MIN_REDIFINED), min_val(INT_MAX_REDIFINED);
                for(int k(j+1); k<j+i; ++k) {
                    max_val = max(max_val, (arr[j]*arr[k]*arr[j+i] + dp_max[j][k] + dp_max[k][j+i]));
                    min_val = min(min_val, (arr[j]*arr[k]*arr[j+i] + dp_min[j][k] + dp_min[k][j+i]));
                }
                dp_max[j][j+i] = max_val;
                dp_min[j][j+i] = min_val;
            }
        }
        cout << dp_max[0][m-1] << " " << dp_min[0][m-1] << endl;
        for(int i(0); i<m; ++i) {
            delete [] dp_max[i];
        }
        delete [] dp_max;
        for(int i(0); i<m; ++i) {
            delete [] dp_min[i];
        }
        delete [] dp_min;
    }
}