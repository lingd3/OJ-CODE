public class Solution {
    /*
     * @param nums an array of Integer
     * @param target = nums[index1] + nums[index2]
     * @return [index1 + 1, index2 + 1] (index1 < index2)
     */
    public int[] twoSum(int[] nums, int target) {
        int size = nums.length;
        int[] results = new int[2];
        for (int i = 0; i < size; i++) {
                for (int j = i+1; j < size; j++) {
                        if (nums[i]+nums[j] == target) {
                                results[0] = i+1;
                                results[1] = j+1;
                                break;
                        }
                }
        }
        return results;
    }
}