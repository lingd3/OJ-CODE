/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/reverse-pairs
@Language: C++
@Datetime: 17-03-13 11:26
*/

class Solution {
public:
    /**
     * @param A an array
     * @return total of reverse pairs
     */
    long long reversePairs(vector<int>& A) {
        // Write your code here
        int n = A.size();
        long long r = 0;
        mergesort(A, 0, n-1, r);
        return r;
    }
    
    void mergesort(vector<int>& A, int start, int end, long long &r) {
        if (start < end) {
            int mid = (start+end)/2;
            mergesort(A, start, mid, r);
            mergesort(A, mid+1, end, r);
            merge(A, start, mid, end, r);
        }
    }
    
    void merge(vector<int>& A, int start, int mid, int end, long long &r) {
        vector<int> temp(end-start+1, 0);
        int i = start, j = mid+1, t = 0;
        while (i <= mid && j <= end) {
            if (A[i] <= A[j]) temp[t++] = A[i++];
            else {
                r += mid-i+1;
                temp[t++] = A[j++];
            }
        }
        while (i <= mid) temp[t++] = A[i++];
        while (j <= end) temp[t++] = A[j++];
        for (int i = 0; i < t; i++) A[start++] = temp[i];
    }
    
};












