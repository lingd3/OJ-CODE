/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/search-for-a-range
@Language: C++
@Datetime: 17-03-14 03:34
*/

class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        vector<int> v;
        int firstIndex = binarySearch(A, target, 0, A.size()-1, 1);
        int secondIndex = binarySearch(A, target, 0, A.size()-1, 2);
        v.push_back(firstIndex);
        v.push_back(secondIndex);
        return v;
        
    }
    
    int binarySearch(vector<int> &A, int target, int low, int high, int i) {
        if (i == 1) {
            while (low < high) {
                int mid = (low+high)/2;
                if (A[mid] < target) low = mid+1;
                else high = mid;
            }
        }
        else {
            while (low < high) {
                int mid = (low+high+1)/2;
                if (A[mid] > target) high = mid-1;
                else low = mid;
            }
        }
        if (high < low) return -1;
        else {
            if (A[low] == target) return low;
            else return -1;
        }
    }
    
};









