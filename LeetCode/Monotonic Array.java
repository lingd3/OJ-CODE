class Solution {
	public boolean isMonotonic(int[] A) {
		if (A.length <= 2) return true;
		int num = 0;
		for (int i = 0; i < A.length-1; i++) {
			if (A[i] >= A[i+1]) num++;
		}
		if (num == A.length-1 || num == 0) return true;
		num = 0;
		for (int i = 0; i < A.length-1; i++) {
			if (A[i] <= A[i+1]) num++;
		}
		if (num == A.length-1 || num == 0) return true;
		return false;
    }
}