//
// Created by 16517 on 2024/7/25.
//
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        string ans = s;
        for (int i = 0; i < s.size(); i += (2*k)) {
            int left = i, right = i + k - 1 < s.size() - 1 ? i + k - 1 : s.size() - 1;
            while (left < right) {
                int tmp = ans[left];
                ans[left] = ans[right];
                ans[right] = tmp;
                left++;
                right--;
            }
        }
        return ans;
    }
};
