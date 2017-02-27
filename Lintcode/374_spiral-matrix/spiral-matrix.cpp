/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/spiral-matrix
@Language: C++
@Datetime: 17-02-26 13:42
*/

class Solution {
public:
    /**
     * @param matrix a matrix of m x n elements
     * @return an integer array
     */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Write your code here
        vector<int> v;
        int row = matrix.size()-1;
        if (row < 0) return v;
        int col = matrix[0].size()-1;
        if (row == 0) {
            for (int i = 0; i <= col; i++) {
                v.push_back(matrix[0][i]);
            }
            return v;
        }
        int visited[row+1][col+1];
        for (int i = 0; i <= row; i++) {
            for (int j = 0; j <= col; j++) {
                visited[i][j] = 0;
            }
        }
        int x = 0, y = 0;
        v.push_back(matrix[0][0]);
        visited[0][0] = 1;
        int count = 0;
        while (v.size() < matrix.size()*matrix[0].size()) {
            if (y+1 <= col && visited[x][y+1] == 0 && count == 0) {
                v.push_back(matrix[x][y+1]);
                visited[x][y+1] = 1;
                y++;
                if (y+1 > col || visited[x][y+1] == 1) count = 1;
            }
            else if (x+1 <= row && visited[x+1][y] == 0  && count == 1) {
                v.push_back(matrix[x+1][y]);
                visited[x+1][y] = 1;
                x++;
                if (x+1 > row || visited[x+1][y] ==1) count = 2;
            }
            else if (y-1 >= 0 && visited[x][y-1] == 0 && count == 2) {
                v.push_back(matrix[x][y-1]);
                visited[x][y-1] = 1;
                y--;
                if (y-1 < 0 || visited[x][y-1] ==1) count =3;
            }
            else if (x-1 >= 0 && visited[x-1][y] == 0 && count == 3) {
                v.push_back(matrix[x-1][y]);
                visited[x-1][y] = 1;
                x--;
                if (x-1 < 0 || visited[x-1][y] == 1) count = 0;
            }
        }
        return v;
    }
};