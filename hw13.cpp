#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
    double a, b, d, x, x_sum, y_sum;
    vector<pair<double, double>> v;
    while(cin >> a >> b >> d >> x) {
        x_sum = 0;
        y_sum = 0;
        d /= 2;
        v.push_back(make_pair(a, b));
        if(a > 0 && b > 0) {
            x_sum += a;
            y_sum += b;
        }
        for(int i(0); i <= x; ++i) {
            int size = v.size();
            if(!size)
                break;
            for(int j(0); j < size; ++j) {
                double cur_x = v[0].first;
                double cur_y = v[0].second;
                if(cur_x + d*2 > 0 && cur_y + d*2 > 0) {
                    v.push_back(make_pair(cur_x + d, cur_y + d));
                    if(v.back().first > 0 && v.back().second > 0) {
                        x_sum += v.back().first;
                        y_sum += v.back().second;
                    }
                }
                if(cur_x > 0 && cur_y + d*2 > 0) {
                    v.push_back(make_pair(cur_x - d, cur_y + d));
                    if(v.back().first > 0 && v.back().second > 0) {
                        x_sum += v.back().first;
                        y_sum += v.back().second;
                    }
                }
                if(cur_x + d*2 > 0 && cur_y > 0) {
                    v.push_back(make_pair(cur_x + d, cur_y - d));
                    if(v.back().first > 0 && v.back().second > 0) {
                        x_sum += v.back().first;
                        y_sum += v.back().second;
                    }
                }
                if(cur_x > 0 && cur_y > 0) {
                    v.push_back(make_pair(cur_x - d, cur_y - d));
                    if(v.back().first > 0 && v.back().second > 0) {
                        x_sum += v.back().first;
                        y_sum += v.back().second;
                    }
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