/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/length-of-last-word
@Language: C++
@Datetime: 17-04-10 12:31
*/

class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        // Write your code here
        if (s.size() == 0) return 0;
        int len = 0, size = s.size();
        for (int i = 0; i < size; i++) {
            if (s[i] == ' ') len = 0;
            else len++;
        }
        return len;
    }
};