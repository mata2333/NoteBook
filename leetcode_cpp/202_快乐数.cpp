//
// Created by 16517 on 2024/7/20.
//
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    bool isHappy(int n) {
        int sum = n;
        std::unordered_set<int> set;
        while (true) {
            int sum2 = 0;
            while (sum) {
                 sum2 += (sum%10)*(sum%10);
                 sum /= 10;
            }
            sum = sum2;
            if (sum == 1)
                return true;
            if (set.find(sum) != set.end())
                break;
            else
                set.insert(sum);
        }
        return false;
    }
};
