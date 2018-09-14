class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] rtn = new int[2];
        int len = nums.length, i, j;
        for (i = 0; i < len-1; i++) {
        	for (j = i+1; j < len; j++) {
        		if (nums[i]+nums[j] == target) {
        			rtn[0] = i;
        			rtn[1] = j;
        			return rtn;
        		}
        	}
        }
        return rtn;
    }
}