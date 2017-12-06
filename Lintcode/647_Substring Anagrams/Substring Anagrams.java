public class Solution {
    /**
     * @param s a string
     * @param p a non-empty string
     * @return a list of index
     */
    public List<Integer> findAnagrams(String s, String p) {
            List<Integer> list = new ArrayList<Integer>();
            int len1 = s.length(), len2 = p.length();
            for (int i = 0; i <= len1-len2; i++) {
                    String t = s.substring(i, i+len2);
                    if (isAnagram(t, p)) list.add(i);
            }
            return list;
    }
    
    private boolean isAnagram(String t, String p) {
            int[] n = new int[26];
            int len = t.length();
            for (int i = 0; i < len; i++) {
                    n[t.charAt(i)-'a']++;
            }
            for (int i = 0; i < len; i++) {
                    n[p.charAt(i)-'a']--;
            }
            for (int i = 0; i < 26; i++) {
                    if (n[i] != 0) return false;
            }
                return true;
        }
        
}