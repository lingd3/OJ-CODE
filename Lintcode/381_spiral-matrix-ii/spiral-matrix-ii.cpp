/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/spiral-matrix-ii
@Language: C++
@Datetime: 17-03-13 12:17
*/

class Solution {
public:
    /**
     * @param n an integer
     * @return a square matrix
     */
    vector<vector<int>> generateMatrix(int n) {
        // Write your code here
        int v[n][n];
        int visited[n][n], dir = 0, t = 2;
        v[0][0] = 1;
        int row = n, col = n, i = 0, j = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = 0;
            }
        }
        visited[0][0] = 1;
        while (t <= n*n) {
            if (j+1 < col && visited[i][j+1] == 0 && dir == 0) {
                j++;
                visited[i][j] = 1;
                v[i][j] = t;
                t++;
                if (j+1 >= col || visited[i][j+1] == 1) dir = 1;
            }
            else if (i+1 < row && visited[i+1][j] == 0 && dir == 1) {
                i++;
                visited[i][j] = 1;
                v[i][j] = t;
                t++;
                if (i+1 >= row || visited[i+1][j] == 1) dir = 2;
            }
            else if (j-1 >= 0 && visited[i][j-1] == 0 && dir == 2) {
                j--;
                visited[i][j] = 1;
                v[i][j] = t;
                t++;
                if (j-1 < 0 || visited[i][j-1] == 1) dir = 3;
            }
            else if (i-1 >= 0 && visited[i-1][j] == 0 && dir == 3) {
                i--;
                visited[i][j] = 1;
                v[i][j] = t;
                t++;
                if (i-1 < 0 || visited[i-1][j] == 1) dir = 0;
            }
        }
        vector<vector<int>> v1;
        for (int i = 0; i < n; i++) {
            vector<int> v2;
            for (int j = 0; j < n; j++) {
                v2.push_back(v[i][j]);
            }
            v1.push_back(v2);
        }
        return v1;
    }
};