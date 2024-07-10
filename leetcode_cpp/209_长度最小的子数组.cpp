//
// Created by 16517 on 2024/7/10.
//
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int ans = INT_MAX, sum = 0;
        int left = 0, right = 0;
        while (right < nums.size()) {
            if (sum < s) {
                sum += nums[right++];
            }
            while (sum > s) {
                sum -= nums[left++];
            }
            if (sum == s) {
                ans = ans < (right - left + 1) ? ans : (right - left + 1);
                right++;
            }
        }
        return ans;
    }
};