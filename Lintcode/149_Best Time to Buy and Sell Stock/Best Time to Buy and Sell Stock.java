public class Solution {
    /*
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    public int maxProfit(int[] prices) {
            int earn = 0, min = Integer.MAX_VALUE, len = prices.length;
            for (int i = 0; i < len; i++) {
                    if (prices[i] < min) min = prices[i];
                    if (earn < prices[i]-min) earn = prices[i]-min;
                    
            }
            return earn;
    }
}