#include <iostream>
#include <string>
using namespace std;

long long toll(string &in) {
    if(in.length()) {
        return stoll(in);
    }
    return 0;
}
int main(void) {
    string s1, s2;
    while(cin >> s1 >> s2) {
        int l1 = s1.length();
        int l2 = s2.length();

        // processing col 0
        string **col0 = new string*[l1];
        string empty = "", s2_first = s2.substr(0, 1), s1_first = s1.substr(0, 1);
        for(int i(0); i < l1; ++i) {
            col0[i] = &empty;
        }
        if(s1[0] == s2[0]) {
            col0[0] = &s2_first;
        }
        for(int i(1); i < l1; ++i) {
            if(col0[i-1] != &empty || s1[i] == s2[0]) {
                col0[i] = &s2_first;
            }
        }
        string **cur_row = new string*[l2];
        string **pre_row = new string*[l2];
        
        // processing row 0
        for(int i(0); i < l2; ++i) {
            pre_row[i] = new string("");
        }
        if(s1[0] == s2[0]) {
            delete pre_row[0];
            pre_row[0] = new string(s1_first);
        }
        for(int i(1); i < l2; ++i) {
            if(*(pre_row[i-1]) != "" || s1[0] == s2[i]) {
                delete pre_row[i];
                pre_row[i] = new string(s1_first);
            }
        }
        for(int i(0); i < l2; ++i) {
            cur_row[i] = new string("");
        }
        // processing dp table
        for(int i(1); i < l1; ++i) {
            cur_row[0] = col0[i];
            for(int j(1); j < l2; ++j) {
                delete cur_row[j];
                if(s1[i] == s2[j]) {
                    cur_row[j] = new string(*(pre_row[j-1]) + s1[i]);
                } else {
                    if(toll(*(cur_row[j-1])) > toll(*(pre_row[j]))) {
                        cur_row[j] = new string(*(cur_row[j-1]));
                    } else {
                        cur_row[j] = new string(*(pre_row[j]));
                    }
                }
            }
            swap(cur_row, pre_row);
        }
        cout << toll(*(pre_row[l2 - 1])) << endl;
        delete [] pre_row;
        delete [] cur_row;
    }
}
