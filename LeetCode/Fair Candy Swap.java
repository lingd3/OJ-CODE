class Solution {
    public int[] fairCandySwap(int[] A, int[] B) {
		int[] rtn = new int[2];
        Set<Integer> s = new HashSet<>();
        int a = 0, b = 0;
        for (int i = 0; i < B.length; i++) {
        	b += B[i];
        	s.add(B[i]);
        }
        for (int i = 0; i < A.length; i++) {
        	a += A[i];
        }
        for (int i = 0; i < A.length; i++) {
        	if (s.contains((b-a)/2+A[i])) {
        		rtn[0] = A[i];
        		rtn[1] = (b-a)/2+A[i];
        		return rtn;
        	}
        }
		return rtn;
    }
}