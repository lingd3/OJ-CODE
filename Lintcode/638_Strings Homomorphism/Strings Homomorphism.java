public class Solution {
    /**
     * @param s a string
     * @param t a string
     * @return true if the characters in s can be replaced to get t or false
     */
    public boolean isIsomorphic(String s, String t) {
            int len = s.length();
            Set<Character> set1 = new HashSet<Character>();
            Set<Character> set2 = new HashSet<Character>();
            for (int i = 0; i < len; i++) {
                    set1.add(s.charAt(i));
                    set2.add(t.charAt(i));
            }
            if (set1.size() != set2.size()) return false;
            
            Map<Character, Character> map = new HashMap<Character, Character>();
            for (int i = 0; i < len; i++) {
                    char a = s.charAt(i);
                    char b = t.charAt(i);
                    if (!map.containsKey(a)) {
                            map.put(a, b);
                    }
                    else {
                            char c = map.get(a);
                            if (c != b) return false;
                    }
            }
            return true;
    }
}