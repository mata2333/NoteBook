//
// Created by admin on 2024/7/8.
//
#include <vector>
using namespace std;

class Solution {
public:
    // 构建新数组
    int removeElement1(vector<int>& nums, int val) {
        vector<int> new_nums(nums.size(), 0);
        int new_nums_index = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                new_nums[new_nums_index++] = nums[i];
            }
        }
        nums = new_nums;
        return new_nums_index;
    }
    // 双指针法
    int removeElement2(vector<int>& nums, int val) {
        int left = 0, right = 0;
        for (; right < nums.size(); right++) {
            if (val != nums[right]) {
                nums[left++] = nums[right];
            }
        }
        return left;
    }
};
