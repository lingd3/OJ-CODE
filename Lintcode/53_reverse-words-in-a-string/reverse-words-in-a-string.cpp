/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/reverse-words-in-a-string
@Language: C++
@Datetime: 17-03-14 02:15
*/

class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        char a[s.size()];
        for (int i = 0; i < s.size(); i++) a[i] = '\0';
        //先去除空格
        int i;
        for (i = 0; i < s.size(); i++) {
            if (s[i] != ' ') break;
        }
        int j = 0;
        for (; i < s.size(); i++) {
            if (s[i] == ' ' && a[j-1] == ' ') continue;
            else if (s[i] == ' ' && a[j-1] != ' ') {
                a[j] = ' ';
                j++;
            }
            else {
                a[j] = s[i];
                j++;
            }
        }
        int length = strlen(a);
        for (i = length-1; i >= 0; i--) {
            if (a[i] == ' ') a[i] = '\0';
            else break;
        }
        length = strlen(a);
        for (i = 0; i < length; i++) {
            if (a[i] == ' ') break;
        }
        if (i == length) {
            string q(a);
            return q; 
        }
        //全部翻转
        for (i = 0; i < length/2; i++) {
            char temp = a[i];
            a[i] = a[length-1-i];
            a[length-1-i] = temp;
        }
        //最后翻转单个单词
        j = 0;
        for (i = 0; i < length; i++) {
            if (a[i] == ' ') {
                reverse(a, j, i-1);
                j = i+1;
            }
        }
        //翻转最后一个单词
        for (i = length-1; i >= 0; i--) {
            if (a[i] == ' ') break;
        }
        reverse(a, i+1, length-1);
        string q(a);
        return q;
    }
    
    void reverse(char* a, int i, int j) {
        int l = j-i+1;
        for (int k = i; k < l/2+i; k++) {
            char temp = a[k];
            a[k] = a[j-(k-i)];
            a[j-(k-i)] = temp;
        }
    }
    
};


