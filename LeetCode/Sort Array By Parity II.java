class Solution {
    public int[] sortArrayByParityII(int[] A) {
        int[] even = new int[A.length/2];
        int[] odd = new int[A.length/2];
        int el = 0, ol = 0;
        for (int i = 0; i < A.length; i++) {
        	if (A[i]%2 == 0) even[el++] = A[i];
        	else odd[ol++] = A[i];
        }
        el = 0;
        ol = 0;
        for (int i = 0; i < A.length; i++) {
        	if (i%2 == 0) A[i] = even[el++];
        	else A[i] = odd[ol++];
        }
        return A;
    }
}