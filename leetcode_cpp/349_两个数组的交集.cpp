//
// Created by 16517 on 2024/7/19.
//
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        unordered_set<int> ans_set;
        for (int val: nums2) {
            if (nums_set.find(val) != nums_set.end()) {
                ans_set.insert(val);
            }
        }
        return vector<int>(ans_set.begin(), ans_set.end());
    }
};
