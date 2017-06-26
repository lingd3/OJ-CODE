class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {
        // Write your code here
        int size = s.size();
        int first = 0, last = size-1;
        while (first < last) {
            if (s[first] < '0' || s[first] > '9' && s[first] < 'A' || s[first] > 'Z' && s[first] < 'a' || s[first] > 'z') {
                first++;
                continue;
            }
            if (s[last] < '0' || s[last] > '9' && s[last] < 'A' || s[last] > 'Z' && s[last] < 'a' || s[last] > 'z') {
                last--;
                continue;
            }
            if (s[first] != s[last] && s[first]+32 != s[last] && s[first]-32 != s[last]) return false;
            else {
                first++;
                last--;
            }
        }
        return true;
    }
};