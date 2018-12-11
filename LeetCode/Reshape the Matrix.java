class Solution {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        int row = nums.length, col = nums[0].length;
		if (row*col != r*c) return nums;
		int[][] rtn = new int[r][c];
		int[] num = new int[row*col];
		int k = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				num[k++] = nums[i][j];
			}
		}
        k = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				rtn[i][j] = num[k++];
			}
		}
		return rtn;
    }
}