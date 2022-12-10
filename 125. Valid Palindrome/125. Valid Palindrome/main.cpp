//
//  main.cpp
//  125. Valid Palindrome
//
//  Created by Артём Lazemir on 10.12.2022.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {    
public:
    bool isPalindrome(string s) {
        for (auto& el : s)
            el = tolower(el);
        auto left = s.begin();
        auto right = s.end() - 1;
        while (left < right) {
            while (!isalnum(*left) && left < right) ++left;
            while (!isalnum(*right) && left < right) --right;
            if (*left != *right) return false;
            ++left;
            --right;
        }
    return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    string s = "0P";
    cout << sol.isPalindrome(s) << endl;

    return 0;
}
