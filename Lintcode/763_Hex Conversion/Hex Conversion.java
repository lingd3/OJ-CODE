public class Solution {
    /**
     * @param n: a decimal number
     * @param k: a Integer represent base-k
     * @return: a base-k number
     */
    public String hexConversion(int n, int k) {
        // write your code here
        if (n == 0) return "0";
		StringBuilder sb = new StringBuilder();
		while (n != 0) {
			int temp = n%k;
			n = n/k;
			if (temp > 9) sb.insert(0, (char)(temp+'A'-10));
			else sb.insert(0, temp);
		}
		return sb.toString();
    }
}