//
//  main.cpp
//  22. Generate Parentheses
//
//  Created by Артём Lazemir on 10.12.2022.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void concatenate(vector<string>& vector1, vector<string>& vector2) {
        vector1.insert( vector1.end(), vector2.begin(), vector2.end() );
    }
    
    string cloneStr(string s, size_t n) {
        string res;
        for (int i = 0; i < n; ++i) res += s;
        return res;
    }
    
    vector<string> generateParenthesis(int n) {
        if (n == 1) return vector<string>({"()"});
        auto res1 = generateParenthesis(n - 1);
        auto res2 = res1;
        auto res3 = res1;
        for (auto& el : res1) {
            el = "(" + el + ")";
        }
        for (auto& el : res2) {
            el = "()" + el;
        }
        for (auto it = res3.begin(); it < res3.end(); ++it) {
            auto s = cloneStr("()", n - 1);
            if (*it != cloneStr("()", n - 1)) {
                *it += "()";
            } else {
                res3.erase(it);
                --it;
            }
            
        }
        concatenate(res1, res2);
        concatenate(res1, res3);
        return res1;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    
    auto res = sol.generateParenthesis(4);
    for (const auto& el : res) {
        std::cout << el << "; ";
    }
    std::cout << std::endl;
    return 0;
}


