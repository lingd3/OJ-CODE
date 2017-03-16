/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/rotate-string
@Language: C++
@Datetime: 17-03-14 02:27
*/

class Solution {
public:
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    void rotateString(string &str,int offset){
        //wirte your code here
        int s = str.size();
        if (s <= 1) return;
        offset %= s;
        reverse(str, 0, s-1-offset);
        reverse(str, s-offset ,s-1);
        reverse(str, 0, s-1);
    }
    
    void reverse(string &str, int i, int j) {
        int l = j-i+1;
        for (int k = i; k < l/2+i; k++) {
            char temp = str[k];
            str[k] = str[j-(k-i)];
            str[j-(k-i)] = temp;
        }
    }
};
