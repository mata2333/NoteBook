impl Solution {
    pub fn generate_matrix(n: i32) -> Vec<Vec<i32>> {
        let mut matrix = vec![vec![0; n]; n];
        let mut offset = 0;
        let mut count = 1;
        let mut i = 0;
        let mut j = 0;
        while offset < n / 2 {
            for j in offset..n - 1 - offset {
                matrix[offset][j] = count;
                count += 1;
            }
            for i in offset..n - 1 - offset {
                matrix[i][j] = count;
                count += 1;
            }
        }
    }
}