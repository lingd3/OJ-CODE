class Solution {
    public int smallestRangeI(int[] A, int K) {
        if (K < 0) K *= -1;
        int max = A[0], min = A[0];
		for (int i = 1; i < A.length; i++) {
			if (A[i] > max) max = A[i];
			if (A[i] < min) min = A[i];
		}
		int n = (max-K)-(min+K);
		if (n < 0) return 0;
		return n;
    }
}