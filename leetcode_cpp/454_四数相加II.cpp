//
// Created by 16517 on 2024/7/22.
//
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> map;
        for (int i : nums1) {
            for (int j : nums2) {
                map[i + j]++;
            }
        }
        int count = 0;
        for (int i : nums3) {
            for (int j : nums4) {
                if (map[-(i + j)] != 0) {
                    count += map[-(i + j)];
                }
            }
        }
        return count;
    }
};