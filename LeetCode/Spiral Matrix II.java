class Solution {
	public int[][] generateMatrix(int n) {
		int[][] m = new int[n][n];
		int direction = 0, count = 1, i = 0, j = -1;
		while (count <= n*n) {
			if (direction == 0) {
				if (j+1 < n && m[i][j+1] == 0) {
					j++;
					m[i][j] = count;
					count++;
				}
				else direction = 1;
			}
			else if (direction == 1) {
				if (i+1 < n && m[i+1][j] == 0) {
					i++;
					m[i][j] = count;
					count++;
				}
				else direction = 2;
			}
			else if (direction == 2) {
				if (j-1 >= 0 && m[i][j-1] == 0) {
					j--;
					m[i][j] = count;
					count++;
				}
				else direction = 3;
			}
			else {
				if (i-1 >= 0 && m[i-1][j] == 0) {
					i--;
					m[i][j] = count;
					count++;
				}
				else direction = 0;
			}
		}
		return m;
    }
}