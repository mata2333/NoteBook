struct Solution {

}

impl Solution {
    pub fn sorted_squares(nums: Vec<i32>) -> Vec<i32> {
        let mut ans: Vec<i32> = vec![0; nums.len()];
        let mut ans_index = nums.len() - 1;
        let mut left = 0;
        let mut right = nums.len() - 1;
        while left <= right {
            if (nums[left].pow(2) < nums[right].pow(2)) {
                ans[ans_index] = nums[right].pow(2);
                ans_index -= 1;
                right -= 1;
            } else {
                ans[ans_index] = nums[left].pow(2);
                ans_index -= 1;
                left += 1;
            }
        }
        return ans;
    }
}