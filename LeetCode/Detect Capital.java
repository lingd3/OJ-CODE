class Solution {
    public boolean detectCapitalUse(String word) {
        String a = word.toLowerCase(), b = word.toUpperCase(), c = b.substring(0, 1) + a.substring(1);
		return word.equals(a) || word.equals(b) || word.equals(c);
    }
}