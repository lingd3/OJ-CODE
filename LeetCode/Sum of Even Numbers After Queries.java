class Solution {
    public int[] sumEvenAfterQueries(int[] A, int[][] queries) {
        int[] answer = new int[queries.length];
        int val = queries[0][0];
    	int index = queries[0][1];
    	A[index] += val;
    	for (int j = 0; j < A.length; j++) {
    		if (A[j]%2 == 0) answer[0] += A[j];
    	}
        for (int i = 1; i < answer.length; i++) {
        	val = queries[i][0];
        	index = queries[i][1];
        	if (A[index]%2 != 0) {
        		A[index] += val;
        		if (A[index]%2 == 0) answer[i] = answer[i-1]+A[index];
        		else answer[i] = answer[i-1];
        	}
        	else if (A[index]%2 == 0) {
        		int temp = answer[i-1]-A[index];
        		A[index] += val;
        		if (A[index]%2 == 0) answer[i] = temp+A[index];
        		else answer[i] = temp;
        	}
        }
    	return answer;
    }
}