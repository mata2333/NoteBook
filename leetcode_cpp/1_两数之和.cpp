//
// Created by 16517 on 2024/7/20.
//
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            auto iter = map.find(target - nums[i]);
            if (iter != map.end()) {
                ans.push_back(iter->second);
                ans.push_back(i);
                break;
            }
            map[nums[i]] = i;
        }
        return ans;
    }
};