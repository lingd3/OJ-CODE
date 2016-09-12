/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/sort-integers
@Language: C++
@Datetime: 16-08-02 08:10
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers(vector<int>& A) {
        int size = A.size();
        for (int i = 0; i < size-1; i++) {
            for (int j = i+1; j < size; j++) {
                if (A[i] > A[j]) {
                    int a = A[i];
                    A[i] = A[j];
                    A[j] = a;
                }
            }
        }
    }
};