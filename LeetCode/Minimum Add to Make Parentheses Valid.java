class Solution {
    public int minAddToMakeValid(String S) {
        int count = 0;
        Stack<Character> s = new Stack<>();
        for (int i = 0; i < S.length(); i++) {
            char c = S.charAt(i);
            if (c == '(') s.push(c);
            else {
                if (!s.isEmpty()) s.pop();
                else count++;
            }
        }
        count += s.size();
        return count;
    }
}