#include <iostream>
#include <string>
using namespace std;

struct cusstr {
    char str[3];
};

int main(void) {
    bool base[4];
    for(int i=0; i<4; ++i)
        base[i] = 0;
    int n, total(0);
    cin >> n;
    total += n;
    cusstr *data = (cusstr*)malloc(n*9*sizeof(cusstr));
    for(int i=0; i<n; ++i)
        cin >> (data[i*9]).str;
    for(int i=1; i<9; ++i) {
        int nums;
        cin >> nums;
        total += nums;
        for(int j=0; j<nums; ++j)
            cin >> (data[j*9 + i]).str;
    }
    int breakpt, out_counter(0), score(0), curstr(0);
    cin >> breakpt;
    // cout << breakpt;
    // for(int i=0; i<total; ++i)
    //     cout << data[i].str << endl;
    while(out_counter < breakpt) {
        if((data[curstr].str)[1] == 'O') {
            out_counter += 1;
            if(out_counter % 3 == 0) {
                for(int i=1; i<4; ++i)
                    base[i] = 0;
            }
        } else if((data[curstr].str)[0] == '1') {
            score += base[3];
            base[3] = base[2];
            base[2] = base[1];
            base[1] = 1;
        }else if((data[curstr].str)[0] == '2') {
            score += base[3] + base[2];
            base[2] = 1;
            base[1] = 0;
        } else if((data[curstr].str)[0] == '3') {
            score += base[3] + base[2] + base[1];
            base[3] = 1;
            base[2] = 0;
            base[1] = 0;
        } else if((data[curstr].str)[0] == 'H') {
            score += base[3] + base[2] + base[1] + 1;
            for(int i=1; i<4; ++i)
                base[i] = 0;
        }
        cout << curstr << ":" << data[curstr].str << score << endl;
        for(int i=1; i<4; ++i)
            cout << base[i];
        cout << endl;
        curstr += 1;
    }
    cout << score << endl;
}