class Solution {
    public int[] sortArrayByParity(int[] A) {
        int odd = 0;
        for (int i = 0; i < A.length; i++) {
        	if (A[i]%2 != 0) {
        		odd = i;
        		break;
        	}
        }
        for (int i = 0; i < A.length; i++) {
        	if (A[i]%2 == 0 && odd < i) {
        		int temp = A[odd];
        		A[odd] = A[i];
        		A[i] = temp;
        		for (int j = odd+1; j < A.length; j++) {
        			if (A[j]%2 != 0) {
        				odd = j;
        				break;
        			}
        		}
        	}
        	
        }
		return A;
    }
}