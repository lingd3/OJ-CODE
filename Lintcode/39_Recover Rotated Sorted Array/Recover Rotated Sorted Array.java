public class Solution {
    /*
     * @param nums: An integer
     * @return: 
     */
    public void recoverRotatedSortedArray(List<Integer> nums) {
            int k = -1;
            for (int i = 1; i < nums.size(); i++) {
                    if (nums.get(i-1) > nums.get(i)) {
                            k = i;
                            break;
                    }
            }
            
            if (k == -1) return;
            
            reserve(nums, 0, k-1);
            reserve(nums, k, nums.size()-1);        
            reserve(nums, 0, nums.size()-1);
    }

        private void reserve(List<Integer> nums, int begin, int end) {
                int l = end-begin+1;
                for (int i = begin; i < l/2+begin; i++) {
                        int n = nums.get(i);
                        nums.set(i, nums.get(end-(i-begin)));
                        nums.set(end-(i-begin), n);
                }
        }
        
}