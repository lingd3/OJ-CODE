/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/plus-one
@Language: C++
@Datetime: 17-04-04 09:34
*/

class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int>& digits) {
        // Write your code here
        vector<int> v;
        int size = digits.size(), carry = 1;
        if (digits[size-1] != 9) {
            v.insert(v.begin(), digits[size-1]+1);
            for (int i = size-2; i >= 0; i--) v.insert(v.begin(), digits[i]);
            return v;
        }
        v.insert(v.begin(), digits[size-1]+1-10);
        for (int i = size-2; i >= 0; i--) {
            if (digits[i]+carry >= 10) {
                v.insert(v.begin(), digits[i]+carry-10);
                carry = 1;
            } 
            else {
                v.insert(v.begin(), digits[i]+carry);
                carry = 0;
            }
        }
        if (carry == 1) v.insert(v.begin(), 1);
        return v;
    }
};

