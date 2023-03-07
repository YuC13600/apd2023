#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int in;
    cin >> in;
    while(in--) {
        string planet;
        int h, m, s;
        cin >> planet >> h >> m >> s;
        if (planet == "Z") {
            int sum = h*48*30 + m*30 + s;
            h = sum / (60*60);
            sum %= (60*60);
            m = sum / 60;
            sum %= 60;
            s = sum;
            printf("E %d %d %d\n", h, m, s);
        } else {
            int sum = h*60*60 + m*60 + s;
            h = sum / (48*30);
            sum %= (48*30);
            m = sum / 30;
            sum %= 30;
            s = sum;
            printf("Z %d %d %d\n", h, m, s);
        }
    }
    return 0;
}