class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int[] m = new int[cost.length+1];
        for (int i = 0; i < m.length; i++) m[i] = -1;
        m[0] = 0;
        m[1] = cost[0];
        for (int i = 2; i < m.length; i++) {
        	m[i] = Math.min(m[i-1]+cost[i-1], m[i-2]+cost[i-1]);
        }
        int len = m.length;
		return Math.min(m[len-1], m[len-2]);
    }
}