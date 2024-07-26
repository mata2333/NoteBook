//
// Created by 16517 on 2024/7/26.
//
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stack<string> stack1;
        string ans = "";
        int start = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i == 0 && s[i] == ' ')
                continue;
            if (i > 0 && s[i] == ' ' && s[i - 1] == ' ') {
                start = i + 1;
                continue;
            }
            if (s[i] == ' ' || i == s.size() - 1) {
                stack1.push(s.substr(start, i - start + 1));
                start = i + 1;
            }
        }
        while (!stack1.empty()) {
            ans += stack1.top();
            stack1.pop();
        }
        return ans;
    }
};
