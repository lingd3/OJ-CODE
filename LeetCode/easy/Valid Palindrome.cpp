class Solution {
public:
    //字符串处理
    bool isPalindrome(string s) {
        int i, j;
        for (i = 0; i < s.size(); i++) { //先将大写字母都改为小写字母
            if (s[i] >= 'A' && s[i] <= 'Z') s.replace(i, 1, 1, s[i]+'a'-'A');
        }
        for (i = 0, j = s.size()-1; i < j;) { //控制两个指针移动
            if ((s[i] < 'a' || s[i] > 'z') && (s[i] < '0'|| s[i] > '9')) {
                i++;
                continue;
            }
            if ((s[j] < 'a' || s[j] > 'z') && (s[j] < '0'|| s[j] > '9')) {
                j--;
                continue;
            }
            if (s[i] != s[j]) return false;
            else {
                i++;
                j--;
            }
        }
        return true;
    }
};