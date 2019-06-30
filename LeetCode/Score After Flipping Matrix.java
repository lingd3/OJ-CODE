class Solution {
    public int matrixScore(int[][] A) {
    		int sum = 0, row = A.length, col = A[0].length;
    		for (int i = 0; i < row; i++) {
    			if (A[i][0] == 0) {
    				for (int j = 0; j < col; j++) {
    					A[i][j] ^= 1;
    				}
    			}
    		}
    		for (int i = 1; i < col; i++) {
    			int count = 0;
    			for (int j = 0; j < row; j++) {
    				if (A[j][i] == 1) count++;
    			}
    			if (count <= row/2) {
    				for (int j = 0; j < row; j++) {
    					A[j][i] ^= 1;
    				}
    			}
    		}
    		for (int i = 0; i < col; i++) {
    			for (int j = 0; j < row; j++) {
    				sum += A[j][i]*Math.pow(2, col-1-i);
    			}
    		}
    		return sum;
    }
}