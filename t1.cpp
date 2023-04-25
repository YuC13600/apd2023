#include <iostream>
#include <queue>
using namespace std;

inline void push_and_add(queue<pair<double, double>> &q, double &x_sum, double &y_sum, double x, double y) {
    q.push(make_pair(x, y));
    if(x > 0 && y > 0) {
        x_sum += x;
        y_sum += y;
    }
}

int main(void) {
    double a, b, d, x, x_sum, y_sum;
    queue<pair<double, double>> q;
    while(cin >> a >> b >> d >> x) {
        x_sum = 0;
        y_sum = 0;
        d /= 2;
        push_and_add(q, x_sum, y_sum, a, b);
        for(int i(0); i <= x; ++i) {
            int size = q.size();
            if(!size)
                break;
            for(int j(0); j < size; ++j) {
                double cur_x = q.front().first;
                double cur_y = q.front().second;
                if(cur_x + d*2 > 0 && cur_y + d*2 > 0) {
                    push_and_add(q, x_sum, y_sum, cur_x + d, cur_y + d);
                }
                if(cur_x > 0 && cur_y + d*2 > 0) {
                    push_and_add(q, x_sum, y_sum, cur_x - d, cur_y + d);
                }
                if(cur_x + d*2 > 0 && cur_y > 0) {
                    push_and_add(q, x_sum, y_sum, cur_x + d, cur_y - d);
                }
                if(cur_x > 0 && cur_y > 0) {
                    push_and_add(q, x_sum, y_sum, cur_x - d, cur_y - d);
                }
                q.pop();
            }
            d /= 2;
        }
        while(!q.empty())
            q.pop();
        cout << x_sum << " " << y_sum << endl;
    }
    return 0;
}