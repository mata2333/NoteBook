//
// Created by 16517 on 2024/7/23.
//
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 方法一：排序＋二分查找
    vector<vector<int>> threeSum1(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int k = -(nums[i] + nums[j]);
                int left = j + 1, right = nums.size() - 1;
                int mid = (left + right) / 2;
                while (left <= right) {
                    if (nums[mid] < k)
                        left = mid + 1;
                    else if (nums[mid] > k)
                        right = mid - 1;
                    else
                        break;
                    mid = (left + right) / 2;
                }
                if (left <= right)
                    ans.push_back(vector<int>{nums[i], nums[j], nums[mid]});
            }
        }
        return ans;
    }
    // 方法二：双指针
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (i >0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int k = nums[i] + nums[left] + nums[right];
                if (k < 0) {
                    left++;
                } else if (k > 0) {
                    right--;
                } else {
                    ans.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    left++;
                }
                while(left > i + 1 && left < right && nums[left] == nums[left - 1]) {
                    left++;
                }
                while(right < nums.size() - 1 && left < right && nums[right] == nums[right + 1]) {
                    right--;
                }
            }
        }
        return ans;
    }
};