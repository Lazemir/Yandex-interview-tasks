//
//  main.cpp
//  1. Two Sum
//
//  Created by Артём Lazemir on 11.12.2022.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = map.find(target - nums[i]);
            if (it != map.end()) {
                return {i, it->second};
            }
            
            map.insert({nums[i], i});
        }
        return {};
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    
    vector<int> vec = {2,7,11,15};
    int target = 9;
    
    auto res = sol.twoSum(vec, target);
    std::cout << res[0] << ' ' << res[1] << endl;
    return 0;
}
