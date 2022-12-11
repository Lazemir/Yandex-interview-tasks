//
//  main.cpp
//  20. Valid Parentheses
//
//  Created by Артём Lazemir on 11.12.2022.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    stack<char> st;
    bool isValid(string s) {
        for (const auto& sym : s) {
            switch (sym) {
                case '(':
                    st.push(')');
                    break;

                case '[':
                    st.push(']');
                    break;

                case '{':
                    st.push('}');
                    break;
                    
                default:
                    if (st.empty() || sym != st.top()) {
                        return false;
                    } else {
                        st.pop();
                    }
            }
        }
        
        if (!st.empty()) return false;
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    
    string s = "([)]";
    
    auto temp = sol.isValid(s);
    std::cout << (temp ? "true" : "false") << endl;
    return 0;
}
