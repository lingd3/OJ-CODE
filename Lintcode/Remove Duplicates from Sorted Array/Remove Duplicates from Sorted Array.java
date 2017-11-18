public class Solution {
    /**
     * @param A: a array of integers
     * @return : return an integer
     */
    public int removeDuplicates(int[] nums) {
            int i = 0;
            if (nums.length == 0) return 0;
            for (int j = 1; j < nums.length; j++) {
                    if (nums[j] != nums[i]) {
                            nums[++i] = nums[j];
                    }
            }
            return i+1;
    }
    
}