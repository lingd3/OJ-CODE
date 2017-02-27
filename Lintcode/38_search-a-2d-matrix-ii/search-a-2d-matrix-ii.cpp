/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/search-a-2d-matrix-ii
@Language: C++
@Datetime: 17-02-25 09:07
*/

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        int count = 0;
        int row = matrix.size()-1;
        if (row < 0) return 0;
        int col = matrix[0].size()-1;
        int x = row, y = 0;
        while (x >= 0 && y<= col) {
            if (matrix[x][y] > target) {
                x--;
            }
            else if (matrix[x][y] < target) {
                y++;
            }
            else {
                count++;
                x--;
                y++;
            }
        }
        return count;
    }
};













