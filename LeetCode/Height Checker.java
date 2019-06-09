class Solution {
    public int heightChecker(int[] heights) {
        int count = 0;
        int[] s = Arrays.copyOf(heights, heights.length);
        Arrays.sort(s);
        for (int i = 0; i < s.length; i++) {
            if (s[i] != heights[i]) count++;
        }
        return count;
    }
}