struct Solution {

}

impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let mut left: i32 = 0;
        let mut right: i32 = nums.len() as i32;
        let mut middle: i32 = (left + right) / 2;
        while left <= right {
            match nums.get(middle as usize) {
                Some(&value) => {
                    if value == target {
                        return middle;
                    } else if value < target {
                        left = middle + 1;
                    } else {
                        right = middle - 1;
                    }
                }
                None => return -1
            }
            middle = (left + right) / 2;
        }
        return -1;
    }
}