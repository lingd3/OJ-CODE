public class Solution {
    /**
     * @param n: The guest paid
     * @param m: the price
     * @return: the sum of the number of banknotes
     */
    public int coinProblem(int n, int m) {
        // Write your code here
		int rtn = n-m, count = 0;
		if (rtn >= 100) {
			count += rtn/100;
			rtn = rtn%100;
		}
		if (rtn >= 50) {
			count += rtn/50;
			rtn = rtn%50;
		}
		if (rtn >= 20) {
			count += rtn/20;
			rtn = rtn%20;
		}
		if (rtn >= 10) {
			count += rtn/10;
			rtn = rtn%10;
		}
		if (rtn >= 5) {
			count += rtn/5;
			rtn = rtn%5;
		}
		if (rtn >= 2) {
			count += rtn/2;
			rtn = rtn%2;
		}
		count += rtn/1;
		return count;
    }
}