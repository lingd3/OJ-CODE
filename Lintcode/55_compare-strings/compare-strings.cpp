/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/compare-strings
@Language: C++
@Datetime: 16-08-30 16:17
*/

class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        int a[26] = {0};
        for (int i = 0; i < A.size(); i++) {
            a[A[i]-'A']++;
        }
        for (int i = 0; i < B.size(); i++) {
            a[B[i]-'A']--;
        }
        for (int i = 0; i < 26; i++) {
            if (a[i] < 0) return false;
        }
        return true;
    }
};
