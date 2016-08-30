//用哈希更加简答
class Solution {
public:
    int firstUniqChar(string s) {
        if (s == "") return -1; //先做特殊处理
        if (s.size() == 1) return 0;
        int t;
        for (int i = 0; i < s.size(); i++) {
            t = 0;
            if (s.at(i) == ' ') continue;
            for (int j = i+1; j < s.size(); j++) { //将相同的字母替换为空格
                if (s[i] == s[j]) {
                    s.replace(j, 1, " ");
                    t = 1;
                }
            }
            if (t == 0) return i;
        }
        return -1;
    }
};