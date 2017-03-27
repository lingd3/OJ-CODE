/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/classical-binary-search
@Language: C++
@Datetime: 17-03-25 04:02
*/

class Solution {
public:
    /**
     * @param A an integer array sorted in ascending order
     * @param target an integer
     * @return an integer
     */
    int findPosition(vector<int>& A, int target) {
        // Write your code here
        int left = 0, right = A.size()-1;
        while (left < right) {
            int mid = (left+right)/2;
            if (A[mid] == target) return mid;
            else if (A[mid] > target) right = mid-1;
            else left = mid+1;
        }
        return -1;
    }
};