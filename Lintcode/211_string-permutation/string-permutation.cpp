/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/string-permutation
@Language: C++
@Datetime: 17-02-27 10:42
*/

class Solution {
public:
    /**
     * @param A a string
     * @param B a string
     * @return a boolean
     */
    bool stringPermutation(string& A, string& B) {
        // Write your code here
        if (A.size() != B.size()) return false;
        if (A.size() == 0) return true;
        int a[26] = {0};
        for (int i = 0; i < A.size(); i++) {
            a[A[i]-'a']++;
            a[B[i]-'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (a[i] != 0) return false;
        }
        return true;
    }
};