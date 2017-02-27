/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/space-replacement
@Language: C++
@Datetime: 17-02-25 03:52
*/

class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // Write your code here
        int count = 1;
        for (int i = 0; i < length; i++) {
            if (string[i] == ' ') {
                for (int j = length-1+2; j-2 > i; j--) {
                    string[j] = string[j-2];
                }
                string[i] = '%';
                string[i+1] = '2';
                string[i+2] = '0';
                count++;
                length += 2;
                i += 2;
            }
        }
        return length;
    }
};  