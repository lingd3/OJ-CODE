class Solution {
	public static boolean wordPattern(String pattern, String str) {
        String[] s = str.split(" ");
        if (pattern.length() != s.length) return false;
        Map<String, Character> map = new HashMap<>();
        Map<Character, String> map2 = new HashMap<>();
        for (int i = 0; i < pattern.length(); i++) {
        	char c = pattern.charAt(i);
        	String a = s[i];
        	if (!map.containsKey(a) && !map2.containsKey(c)) {
                map.put(a, c);
                map2.put(c, a);
                continue;
            }
        	if (!map.containsKey(a) && map2.containsKey(c)) return false;
        	if (map.containsKey(a) && !map2.containsKey(c)) return false;
        	else if (map.get(a) != c || !map2.get(c).equals(a)) return false; 
        }
		return true;
    }
}