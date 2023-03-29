#include <iostream>
#include <map>
using namespace std;

struct pa {
    int x, y;
    bool operator <(const pa& rhs) const{
        if(x != rhs.x)
            return x < rhs.x;
        return y < rhs.y;
    }
};

int main(void) {
    int n;
    while(cin >> n) {
        map<pa, char> mp;
        int sum(0);
        while(n--) {
            pa input;
            cin >> input.y >> input.x;
            map<pa,char>::iterator it;
            it = mp.find(input);
            if(input.x != input.y) {
                if(it != mp.end()) {
                    mp.erase(input);
                    sum++;
                } else {
                    swap(input.x, input.y);
                    mp.insert(make_pair(input, 'A'));
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}