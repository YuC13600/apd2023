#include <iostream>
#include <map>
using namespace std;

struct Pair {
    int x, y;
    bool operator <(const Pair& rhs) const{
        if(x != rhs.x)
            return x < rhs.x;
        return y < rhs.y;
    }
};

int main(void) {
    int n;
    while(cin >> n) {
        map<Pair, int> mp;
        int sum(0);
        while(n--) {
            Pair input;
            cin >> input.y >> input.x;
            auto it = mp.find(input);
            if(input.x != input.y) {
                if(it != mp.end()) {
                    if(it->second == 1) {
                        mp.erase(input);
                    } else {
                        it->second--;
                    }
                    sum++;
                } else {
                    swap(input.x, input.y);
                    auto it = mp.find(input);
                    if(it != mp.end()) {
                        it->second++;
                    } else {
                        mp.insert(make_pair(input, 1));
                    }
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}