#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        vector<int> ans(nums.size(), 0);
        int i = nums.size() - 1;
        while (left <= right) {
            if (nums[left] * nums[left] < nums[right] * nums[right]) {
                ans[i--] = nums[right] * nums[right];
                right--;
            } else {
                ans[i--] = nums[left] * nums[left];
                left++;
            }
        }
        return ans;
    }
};