class Solution {
    public int projectionArea(int[][] grid) {
        int n = grid.length;
		int top = 0;  //xy
		int front = 0; //xz
		int side = 0; //yz
        for (int i = 0; i < n; i++) {
        	int x = 0, y = 0;
        	for (int j = 0; j < n; j++) {
        		if (grid[i][j] != 0) top++;
        		x = max(x, grid[i][j]);
        		y = max(y, grid[j][i]);
        	}
        	front += x;
        	side += y;
        }
		return top+front+side;
    }


	private int max(int a, int b) {
		if (a >= b) return a;
		return b;
	}
}