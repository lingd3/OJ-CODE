class Solution {
public:
    /**
     * @param s a string which consists of lowercase or uppercase letters
     * @return the length of the longest palindromes that can be built
     */
    int longestPalindrome(string& s) {
        // Write your code here
        int size = s.size();
        if (size <= 1) return size;
        int a[52] = {0};
        for (int i = 0; i < size; i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') a[s[i]-'A'+26]++;
            else a[s[i]-'a']++;
        }
        int sum = 0, odd = 0;
        for (int i = 0; i < 52; i++) {
            if (a[i]%2 == 0) sum += a[i];
            else {
                sum += (a[i]-1);
                odd = 1;
            }
        }
        return sum+odd;
    }
};