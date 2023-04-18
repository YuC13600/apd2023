#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

struct Pair {
    int front, back;
};


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    char buf[100001];
    while(cin >> buf) {
        const int len = strlen(buf);
        int max_len(0);
        vector<Pair> vec;
        for(int i=0; i<len; ++i) {
            int left(i), right(i);
            while (left >= 0 && right < len && buf[left] == buf[right]) {
                left--;
                right++;
            }
            int odd_len = right - left - 1;
            Pair odd_pair{left + 1, right - 1};

            left = i;
            right = i + 1;
            while (left >= 0 && right < len && buf[left] == buf[right]) {
                left--;
                right++;
            }
            int even_len = right - left - 1;
            Pair even_pair{left + 1, right - 1};
            if(left == right + 1) {
                even_len = 1;
                even_pair = {left + 1, left + 1};
            }
            
            
            if(even_len == max_len) {
                vec.push_back(even_pair);
            }
            if(odd_len == max_len) {
                vec.push_back(odd_pair);
            }
            if(max_len < max(even_len, odd_len)) {
                max_len = max(even_len, odd_len);
                vec.clear();
                if(even_len < odd_len) {
                    vec.push_back(odd_pair);
                } else {
                    vec.push_back(even_pair);
                }
            }
        }
        
        if(max_len == 0 || max_len == 1) {
            cout << '0' << '\n';
        } else {
            cout << max_len << " ";
            for(int i(vec[0].front); i <= vec[0].back; ++i) {
                cout << buf[i];
            }
            for(int i(1); i < vec.size(); ++i) {
                cout << ", ";
                for(int j(vec[i].front); j <= vec[i].back; ++j) {
                    cout << buf[j];
                }
            }
            cout << '\n';
        }
        
    }
}