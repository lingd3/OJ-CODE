class Solution {
	public int minMoves(int[] nums) {
		int count = 0, len = nums.length;
		int min = 2147483647;
		for (int i = 0; i < len; i++) {
			if (nums[i] < min) min = nums[i]; 
		}
		for (int i = 0; i < len; i++) {
			count += nums[i]-min;
		}
		return count;
    }
}