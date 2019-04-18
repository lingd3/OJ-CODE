class Solution {
	public List<Integer> spiralOrder(int[][] matrix) {
		List<Integer> l = new ArrayList<>();
        if (matrix.length == 0) return l;
		int row = matrix.length, col = matrix[0].length;
		int count = row*col, direction = 0, i = 0, j = -1;
		while (count > 0) {
			if (direction == 0) {
				if (j+1 < col && matrix[i][j+1] != -10000) {
					j++;
					l.add(matrix[i][j]);
					matrix[i][j] = -10000;
					count--;
				}
				else {
					direction = 1;
					continue;
				}
			}
			else if (direction == 1) {
				if (i+1 < row && matrix[i+1][j] != -10000) {
					i++;
					l.add(matrix[i][j]);
					matrix[i][j] = -10000;
					count--;
				}
				else {
					direction = 2;
					continue;
				}
			}
			else if (direction == 2) {
				if (j-1 >= 0 && matrix[i][j-1] != -10000) {
					j--;
					l.add(matrix[i][j]);
					matrix[i][j] = -10000;
					count--;
				}
				else {
					direction = 3;
					continue;
				}
			}
			else {
				if (i-1 >= 0 && matrix[i-1][j] != -10000) {
					i--;
					l.add(matrix[i][j]);
					matrix[i][j] = -10000;
					count--;
				}
				else {
					direction = 0;
					continue;
				}
			}
		}
		return l;
    }
}