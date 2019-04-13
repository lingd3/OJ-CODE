class Solution {
	public int countBinarySubstrings(String s) {
        int count = 0;
        List<Integer> list = new ArrayList<>();
        int c = 1;
        for (int i = 1; i < s.length(); i++) {
        	if (s.charAt(i) == s.charAt(i-1)) c++;
        	else {
        		list.add(c);
        		c = 1;
        	}
        }
        list.add(c);
        for (int i = 0; i < list.size()-1; i++) {
        	int i1 = list.get(i);
        	int i2 = list.get(i+1);
        	count += Math.min(i1, i2);
        }
		return count;
    }
}