class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int count = 0;
        int r = grid.length, c = grid[0].length;
        int[] row = new int[r];
        int[] col = new int[c];
        for (int i = 0; i < r; i++) {
            int max = -1;
            for (int j = 0; j < c; j++) {
                if (grid[i][j] > max) max = grid[i][j];
            }
            row[i] = max;
        }
        for (int i = 0; i < c; i++) {
            int max = -1;
            for (int j = 0; j < r; j++) {
                if (grid[j][i] > max) max = grid[j][i];
            }
            col[i] = max;
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int t = Math.min(row[i], col[j]);
                count += (t-grid[i][j]);
            }
        }
        return count;
    }
}