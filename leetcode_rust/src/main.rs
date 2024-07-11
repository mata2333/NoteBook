struct Solution {

}

impl Solution {
    pub fn generate_matrix(n: i32) -> Vec<Vec<i32>> {
        let mut matrix = vec![vec![0; n as usize]; n as usize];
        let mut offset:usize = 0;
        let n_t = n as usize;
        let mut count = 1;
        let mut i:usize = 0;
        let mut j:usize = 0;
        while offset < n_t / 2 {
            i = offset;
            j = offset;
            while j < n_t - 1 - offset {
                matrix[offset][j] = count;
                j += 1;
                count += 1;
            }
            while i < n_t - 1 - offset {
                matrix[i][j] = count;
                i += 1;
                count += 1;
            }
            while j > offset {
                matrix[i][j] = count;
                j -= 1;
                count += 1;
            }
            while i > offset {
                matrix[i][j] = count;
                i -= 1;
                count += 1;
            }
            offset += 1;
        }
        if n % 2 != 0 {
            matrix[n_t / 2][n_t / 2] = count;
        }
        return matrix;
    }
}

fn main() {
    let ans = Solution::generate_matrix(4);
}
