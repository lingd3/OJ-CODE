class Solution {
    public int surfaceArea(int[][] grid) {
        int num = 0, n = grid.length;
        for (int i = 0; i < n; i++) {
        	for (int j = 0; j < n; j++) {
        		if (grid[i][j] != 0) num += 2;
        		if (i-1 < 0) num += grid[i][j];
        		if (j-1 < 0) num += grid[i][j];
        		if (i+1 >= n) num += grid[i][j];
        		if (j+1 >= n) num += grid[i][j];
        		if (i-1 >= 0 && grid[i][j] > grid[i-1][j]) num += grid[i][j]-grid[i-1][j];
        		if (j-1 >= 0 && grid[i][j] > grid[i][j-1]) num += grid[i][j]-grid[i][j-1];
        		if (i+1 < n && grid[i][j] > grid[i+1][j]) num += grid[i][j]-grid[i+1][j];
        		if (j+1 < n && grid[i][j] > grid[i][j+1]) num += grid[i][j]-grid[i][j+1];
        	}
        }
		return num;
    }
}