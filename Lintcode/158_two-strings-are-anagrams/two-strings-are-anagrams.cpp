/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/two-strings-are-anagrams
@Language: C++
@Datetime: 16-08-30 16:13
*/

class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int a[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            if (s[i]-'a' >= 0 && s[i]-'a' <= 25) a[s[i]-'a']++;
            if (t[i]-'a' >= 0 && t[i]-'a' <= 25) a[t[i]-'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (a[i] != 0) return false;
        }
        return true;
    }
};