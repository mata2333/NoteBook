//
// Created by 16517 on 2024/7/27.
//
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getNextArray(string s) {
        vector<int> ans(s.size(), 0);
        for (int i = 0; i < s.size(); ++i) {
            int left = 0, right = i;
            int count = 0;
            while (left < right) {
                if (s[left] == s[right]) {
                    count++;
                }
                left++;
                right--;
            }
            ans[i] = count;
        }
        return ans;
    }
    bool repeatedSubstringPattern(string s) {

    }
};
