/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/search-a-2d-matrix
@Language: C++
@Datetime: 17-02-26 07:21
*/

class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        int row = matrix.size()-1;
        if (row <= 0) return false;
        int col = matrix[0].size()-1;
        int x = 0, y = col;
        while (x <= row && y >= 0) {
            if (matrix[x][y] > target) {
                y--;
            }
            else if (matrix[x][y] < target) {
                x++;
            }
            else return true;
        }
        return false;
    }
};
