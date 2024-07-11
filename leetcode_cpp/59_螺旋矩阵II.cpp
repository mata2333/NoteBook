//
// Created by 16517 on 2024/7/11.
//
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n));
        int offset = 0;
        int i = 0, j = 0;
        int count = 1;
        while (offset < (n / 2)) {
            for (j = offset; j < n - 1 - offset; j++) {
                matrix[offset][j] = count++;
            }
            for (i = offset; i < n - 1 - offset; i++) {
                matrix[i][j] = count++;
            }
            for (; j > offset; j--) {
                matrix[i][j] = count++;
            }
            for (; i > offset; i--) {
                matrix[i][j] = count++;
            }
            offset++;
        }
        if (n % 2 != 0) {
            matrix[n/2][n/2] = count;
        }
        return matrix;
    }
};