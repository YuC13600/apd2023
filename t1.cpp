#include <iostream>
#include <map>
using namespace std;


int main(void) {
    int n;
    while(cin >> n) {
        map<int, char> mp;
        int sum(0);
        while(n--) {
            int input;
            cin >> input;
            map<int,char>::iterator it;
            it = mp.find(input);
            if(it != mp.end()) {
                mp.erase(input);
                sum++;
            } else {
                mp.insert(make_pair(input, 'A'));
            }
        }
        cout << sum << endl;
    }
    return 0;
}