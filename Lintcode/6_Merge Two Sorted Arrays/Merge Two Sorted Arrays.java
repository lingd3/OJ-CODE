public class Solution {
    /**
     * @param A: sorted integer array A
     * @param B: sorted integer array B
     * @return: A new sorted integer array
     */
    public int[] mergeSortedArray(int[] A, int[] B) {
        // write your code here
		int len1 = A.length, len2 = B.length, num1 = 0, num2 = 0, num = 0;
		int []C = new int[len1+len2];
		while (num1 < len1 && num2 < len2) {
			if (A[num1] <= B[num2]) {
				C[num] = A[num1];
				num1++;
				num++;
			}
			else {
				C[num] = B[num2];
				num2++;
				num++;
			}
		}
		if (num1 == len1) {
			while (num2 < len2) {
				C[num] = B[num2];
				num2++;
				num++;
			}
		}
		else if (num2 == len2) {
			while (num1 < len1) {
				C[num] = A[num1];
				num1++;
				num++;
			}
		}
		
		return C;
    }
}