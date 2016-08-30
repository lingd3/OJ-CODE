//递归方法
class Solution {
public:
    int titleToNumber(string s) {
        if (s == "") return 0;
        int a = s[s.size()-1]-64;
        s = s.erase(s.size()-1);
        return titleToNumber(s)*26+a; 
    }
};