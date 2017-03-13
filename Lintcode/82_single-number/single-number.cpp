/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/single-number
@Language: C++
@Datetime: 17-03-13 12:45
*/

class Solution {
public:
	/**
	 * @param A: Array of integers.
	 * return: The single number.
	 */
    int singleNumber(vector<int> &A) {
        // write your code here
        int n = 0;
        for (int i = 0; i < A.size(); i++) {
            n ^= A[i];
        }
        return n;
    }
};
