#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

struct animal_element {
    string name;
    int quantity;
};
struct location_element {
    string name;
    vector<animal_element> animal_vec;
};

int main(void) {
    int n;
    cin >> n;
    vector<location_element> v;
    while(n--) {
        string animal, location;
        int quantity;
        cin >> animal >> quantity >> location;
        auto it = v.begin();
        while(it != v.end() && it->name != location)
            it++;
        if(it == v.end()) {
            v.push_back({location, vector<animal_element>()});
            auto& last = v.back();
            last.animal_vec.push_back({animal, quantity});
        } else {
            auto it2 = it->animal_vec.begin();
            while(it2 != it->animal_vec.end() && it2->name != animal)
                it2++;
            if(it2 == it->animal_vec.end()) {
                it->animal_vec.push_back({animal, quantity});
            } else {
                it2->quantity += quantity;
            }
        }
    }

    for(auto it = v.begin(); it != v.end(); ++it) {
        cout << it->name << " : ";
        for(auto it2 = it->animal_vec.cbegin(); it2 != it->animal_vec.cend(); ++it2) {
            if(it2 == it->animal_vec.cbegin())
                cout << it2->name << " " << it2->quantity;
            else
                cout << ", " << it2->name << " " << it2->quantity;
        }
        cout << endl;
    }
    return 0;
}