class Solution {
    public int repeatedNTimes(int[] A) {
        Map<Integer, Integer> map = new HashMap<>();
        int N = A.length/2;
        for (int i = 0; i < A.length; i++) {
        	if (map.get(A[i]) == null) {
        		map.put(A[i], 1);
        		continue;
        	}
        	else {
        		int count = map.get(A[i]);
        		if (count+1 == N) return A[i];
        		else {
        			map.put(A[i], count+1);
        		}
        	}
        }
        return 0;
    }
}