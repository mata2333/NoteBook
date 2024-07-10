struct Solution {

}

impl Solution {
    pub fn min_sub_array_len(target: i32, nums: Vec<i32>) -> i32 {
        let mut ans: usize = 0;
        let mut sum: i32 = 0;
        let mut left:usize = 0;
        for right in 0..nums.len() {
            sum += nums[right];
            while sum >= target {
                if ans == 0 || ans > (right - left + 1) {
                    ans = right - left + 1;
                }
                sum -= nums[left];
                left += 1;
            }
        }
        return ans as i32
    }
}