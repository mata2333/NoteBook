impl Solution {
    // 建立新数组
    pub fn remove_element1(nums: &mut Vec<i32>, val: i32) -> i32 {
        let mut new_nums: Vec<i32> = vec![0; nums.len()];
        let mut new_nums_index: usize = 0;
        for i in 0..nums.len() {
            if nums[i] != val {
                new_nums[new_nums_index] = nums[i];
                new_nums_index += 1;
            }
        }
        *nums = new_nums;
        return new_nums_index as i32;
    }
    // 双指针法
    pub fn remove_element2(nums: &mut Vec<i32>, val: i32) -> i32 {
        let mut slow_index = 0_usize;

        for fast_index in 0..nums.len() {
            if nums[fast_index] != val {
                nums[slow_index] = nums[fast_index];
                slow_index += 1;
            }
        }
        return slow_index as i32;
    }
}