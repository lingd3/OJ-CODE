/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/sort-integers-ii
@Language: C++
@Datetime: 17-04-03 08:31
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers2(vector<int>& A) {
        // Write your code here
        sort(A, 0, A.size()-1);
    }
    
    void sort(vector<int>& A, int low, int high) {
        if (low < high) {
            int pivot_position = partition(A, low, high);
            sort(A, low, pivot_position-1);
            sort(A, pivot_position+1, high);
        }
    }
    
    int partition(vector<int>& A, int low, int high) {
        swap(A[low], A[(low+high)/2]);
        int pivot = A[low], last_small = low;
        for (int i = low+1; i <= high; i++) {
            if (A[i] < pivot) {
                last_small++;
                swap(A[last_small], A[i]);
            }
        }
        swap(A[low], A[last_small]);
        return last_small;
    }
    
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
};


