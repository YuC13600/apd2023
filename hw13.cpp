#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

inline void push_and_add(vector<pair<double, double>> &v, double &x_sum, double &y_sum, double x, double y) {
    v.push_back(make_pair(x, y));
    if(x > 0 && y > 0) {
        x_sum += x;
        y_sum += y;
    }
}

int main(void) {
    double a, b, d, x, x_sum, y_sum;
    vector<pair<double, double>> v;
    while(cin >> a >> b >> d >> x) {
        x_sum = 0;
        y_sum = 0;
        d /= 2;
        push_and_add(v, x_sum, y_sum, a, b);
        for(int i(0); i <= x; ++i) {
            int size = v.size();
            if(!size)
                break;
            for(int j(0); j < size; ++j) {
                double cur_x = v[0].first;
                double cur_y = v[0].second;
                if(cur_x + d*2 > 0 && cur_y + d*2 > 0) {
                    push_and_add(v, x_sum, y_sum, cur_x + d, cur_y + d);
                }
                if(cur_x > 0 && cur_y + d*2 > 0) {
                    push_and_add(v, x_sum, y_sum, cur_x - d, cur_y + d);
                }
                if(cur_x + d*2 > 0 && cur_y > 0) {
                    push_and_add(v, x_sum, y_sum, cur_x + d, cur_y - d);
                }
                if(cur_x > 0 && cur_y > 0) {
                    push_and_add(v, x_sum, y_sum, cur_x - d, cur_y - d);
                }
                v.erase(v.begin());
            }
            d /= 2;
        }
        v.clear();
        cout << x_sum << " " << y_sum << endl;
    }
    return 0;
}