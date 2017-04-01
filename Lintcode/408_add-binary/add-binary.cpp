/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/add-binary
@Language: C++
@Datetime: 17-04-01 12:43
*/

class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        // Write your code here
        int carry = 0, c = 0, i, j;
        char sum[100] = {'\0'};
        for (i = a.size()-1, j = b.size()-1; i >= 0 && j >= 0; i--, j--) {
            if (a[i]-'0'+b[j]-'0'+carry > 1) {
                sum[c] = a[i]-'0'+b[j]+carry-2;
                c++;
                carry = 1;
            }
            else {
                sum[c] = a[i]-'0'+b[j]+carry;
                c++;
                carry = 0;
            }
        }
        if (i < 0) {
            for (; j >= 0; j--) {
                if (b[j]-'0'+carry > 1) {
                    sum[c] = b[j]+carry-2;
                    c++;
                    carry = 1;
                }
                else {
                    sum[c] = b[j]+carry;
                    c++;
                    carry = 0;
                }
            }
        }
        else if (j < 0) {
            for (; i >= 0; i--) {
                if (a[i]-'0'+carry > 1) {
                    sum[c] = a[i]+carry-2;
                    c++;
                    carry = 1;
                }
                else {
                    sum[c] = a[i]+carry;
                    c++;
                    carry = 0;
                }
            }
        }
        if (carry == 1) {
            sum[c] = '1';
            c++;
        }
        char sum2[100] = {'\0'};
        int d = 0;
        for (c = c-1; c >= 0; c--) {
            sum2[d] = sum[c];
            d++;
        }
        return string(sum2);
    }
};