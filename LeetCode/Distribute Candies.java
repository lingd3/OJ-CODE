class Solution {
    public int distributeCandies(int[] candies) {
        Set<Integer> s = new HashSet<>();
        for (int i = 0; i < candies.length; i++) {
        	s.add(candies[i]);
        }
		int n = candies.length/2;
		if (s.size() <= n) return s.size();
		else return n;
    }
}