//
// Created by 16517 on 2024/7/24.
//
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int left = j + 1, right = n - 1;
                while (left < right) {
                    long k = (long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (k < target) {
                        left++;
                    } else if (k > target) {
                        right--;
                    } else {
                        ans.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        left++;
                    }
                    while (left > j + 1 && left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    while (right < n - 1 && left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};
