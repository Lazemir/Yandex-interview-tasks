//
//  main.cpp
//  1493. Longest Subarray of 1's After Deleting One Element
//
//  Created by Артём Lazemir on 11.12.2022.
//

#include <iostream>
#include <vector>;

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int prev = 0;
        int zero_counter = 0;
        int prev_len = 0, len = 0;
        int max_len = 0;
        for (const auto& el : nums) {
            if (el == 1 && prev == 1) {
                ++len;

            } else if (el == 1 && prev == 0) {
                if (zero_counter == 1) {
                    prev_len = len;
                } else {
                    prev_len = 0;
                }
                len = 1;

            } else if (el == 0 && prev == 1) {
                if (prev_len + len > max_len) {
                    max_len = prev_len + len;
                }
                zero_counter = 1;

            } else if (el == 0 && prev == 0) {
                ++zero_counter;
            }
            prev = el;
        }

        if (prev_len + len > max_len) {
            max_len = prev_len + len;
        }

        if (zero_counter == 0) return max_len - 1;
        return max_len;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    
    vector<int> nums = {1,1,1,0,0,0,1};
    
    int a = sol.longestSubarray(nums);
    std::cout << a << endl;
    
    return 0;
}
