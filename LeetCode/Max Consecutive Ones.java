class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int max = nums[0], now = 0;
        for (int i = 0; i < nums.length; i++) {
        	if (nums[i] == 0) {
        		if (now > max) max = now;
        		now = 0;
        	}
        	else {
        		now++;
        	}
        }
        if (now > max) max = now;
    	return max;
    }
}