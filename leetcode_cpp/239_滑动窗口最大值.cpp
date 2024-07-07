//
// Created by admin on 2024/7/6.
//
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
class Solution {
public:

    // 暴力解法：不通过
//    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//        vector<int> ans;
//        ans.reserve(nums.size() - k + 1);
//        for (int i = 0; i < nums.size() - k + 1; ++i) {
//            ans.push_back(*max_element(nums.begin() + i, nums.begin() + i + k));
//        }
//        return ans;
//    }
    // 使用map：用时467ms
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        ans.reserve(nums.size() - k + 1);
        map<int, int> cnt;
        for (int i = 0; i < k; ++i) {
            cnt[nums[i]]++;
        }
        for (int i = 0; i < nums.size() - k + 1; ++i) {
            ans.push_back(cnt.rbegin()->first);
            if (i == nums.size() - k) {
                break;
            }
            if (--cnt[nums[i]] == 0) {
                cnt.erase(nums[i]);
            }
            cnt[nums[i + k]]++;
        }

        return ans;
    }

};