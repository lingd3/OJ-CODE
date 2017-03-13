/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/single-number-ii
@Language: C++
@Datetime: 17-03-13 13:38
*/

class Solution {
public:
	/**
	 * @param A : An integer array
	 * @return : An integer 
	 */
    int singleNumberII(vector<int> &A) {
        // write your code here
        int bit[35] = {0};
        for (int i = 0; i < A.size(); i++) {
            int count = 0, a = A[i];
            while (a && count < 32) {
                if ((a&1) != 0) {
                    bit[count]++;
                }
                a = a >> 1;
                count++;
            }
        }
        int num = 0;
        for (int i = 0; i < 35; i++) {
            bit[i] %= 3;
            num += bit[i]*pow(2, i);
        }
        return num;
    }
};