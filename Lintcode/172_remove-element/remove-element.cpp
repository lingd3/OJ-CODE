/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/remove-element
@Language: C++
@Datetime: 17-04-18 10:27
*/

class Solution {
public:
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        // write your code here
        for (int i = 0; i < A.size(); ) {
            if (A[i] == elem) {
                A.erase(A.begin()+i);
            }
            else i++;
        }
        return A.size();
    }
};