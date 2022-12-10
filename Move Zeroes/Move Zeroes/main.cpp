//
//  main.cpp
//  Move Zeroes
//
//  Created by Артём Lazemir on 10.12.2022.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto left = nums.begin(), right = nums.begin();
        while (right < nums.end()) {
            if (*right == 0) {
                ++right;
            } else {
                if (left != right) {
                    *left = *right;
                    *right = 0;
                }
                ++left;
                ++right;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    
    vector<int> nums = {0};
    sol.moveZeroes(nums);
    
    std::cout << "Hello, World!\n";
    return 0;
}
