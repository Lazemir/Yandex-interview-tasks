//
//  main.cpp
//  380. Insert Delete GetRandom O(1)
//
//  Created by Артём Lazemir on 11.12.2022.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <random>

using namespace std;

class RandomizedSet {
public:
    RandomizedSet() : rng(rd()) {}
    
    bool insert(int val) {
        bool res = false;
        if (map.find(val) == map.end()) {
            values.push_back(val);
            res = map.insert({val, values.size() - 1}).second;
        }
        return res;
    }
    
    bool remove(int val) {
        bool res = false;
        if (map.find(val) != map.end()) {
            int temp_ind = map[val];
            swap(values[temp_ind], values.back());
            map[values[temp_ind]] = temp_ind;
            values.pop_back();
            res = map.erase(val);
        }
        return res;
    }
    
    int getRandom() {
        std::uniform_int_distribution<> distr(0, values.size() - 1);
        return values[distr(rng)];
    }
    
private:
    unordered_map<int, int> map;
    vector<int> values;
    
    std::random_device rd;
    std::mt19937 rng;
};


int main(int argc, const char * argv[]) {
    RandomizedSet obj;
    bool a;

    a = obj.insert(0);
    a = obj.insert(1);
    a = obj.remove(0);
    a = obj.insert(2);
    a = obj.remove(1);
    for (int i = 0; i < 10; ++i) cout << obj.getRandom() << ' ';

    return 0;
}


//[null, true, false, true, 2, true, false, 2]
