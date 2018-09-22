class Solution {
    public int uniqueMorseRepresentations(String[] words) {
		String[] s = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
		String[] codes = new String[words.length];
		for (int i = 0; i < words.length; i++) {
			StringBuilder sb = new StringBuilder();
			String word = words[i];
			for (int j = 0; j < word.length(); j++) {
				sb.append(s[word.charAt(j)-'a']);
			}
			codes[i] = sb.toString();
		}
		HashSet<String> set = new HashSet<>();
		for (int i = 0; i < codes.length; i++) {
			set.add(codes[i]);
		}
		return set.size();
    }
}