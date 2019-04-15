class Solution {
    public int thirdMax(int[] nums) {
        if (nums.length == 1) return nums[0];
        if (nums.length == 2) {
            return nums[0]>nums[1]?nums[0]:nums[1];
        }
        long a = Long.MIN_VALUE, b = Long.MIN_VALUE, c = Long.MIN_VALUE;
        int t = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > a) {
                c = b;
                b = a;
                a = nums[i];
                t++;
                continue;
            }
            if (nums[i] == a) continue;
                if (nums[i] > b) {
                    c = b;
                    b = nums[i];
                    t++;
                    continue;
                }
            if (nums[i] == b) continue;
            if (nums[i] >= c) {
                c = nums[i];
            t++;
                continue;
            }
        }
        if (t < 3) return (int) a;
        return (int) c;
    }
}