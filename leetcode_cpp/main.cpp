#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // 暴力求解next数组
    vector<int> getNextArray(string s) {
        vector<int> ans(s.size(), 0);
        for (int i = 0; i < s.size(); ++i) {
            int left = i - 1, right = 1;
            while (left >= 0 && right <= i) {
                if (s.substr(0, left + 1) == s.substr(right, i - right + 1))
                    break;
                left--;
                right++;
            }
            ans[i] = left + 1;
        }
        return ans;
    }
    // 递推法求next
    vector<int> getNext (const string s){
        vector<int> next(s.size(), 0);
        int left = 0, right = 1;
        int len = 0;
        while (right < s.size()) {
            if (s[right] == s[left]) {
                len++;
                next[right] = len;
                left++;
                right++;
            } else {
                if (left > 0)
                    left = next[left - 1];
                else {
                    next[right] = len;
                    right++;
                }
                len = left;
            }
        }
        return next;
    }
    // 移动匹配
    bool repeatedSubstringPattern1(string s) {
        string tmp = s + s;
        if (tmp.substr(1, tmp.size() - 2).find(s) != s.npos)
            return true;
        return false;
    }
    // KMP算法
    bool repeatedSubstringPattern(string s) {
        if (s.size() <= 1)
            return false;
        vector<int> next = getNext(s);
        return (s.size() % (s.size() - next[s.size() - 1]) == 0) && next[s.size() - 1] != 0;
    }
};


int main() {
    string str = "ABACABAB";
    Solution solution;
    auto arr = solution.getNext(str);
    for (int i : arr) {
        printf("%d ", i);
    }
}
