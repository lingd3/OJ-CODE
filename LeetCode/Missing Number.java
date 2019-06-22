class Solution {
    public int missingNumber(int[] nums) {
		int rtn = nums.length;
		for (int i = 0; i < nums.length; i++) {
			rtn ^= nums[i];
			rtn ^= i;
		}
		return rtn;
    }
}