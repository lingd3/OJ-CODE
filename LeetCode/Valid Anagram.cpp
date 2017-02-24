//利用哈希，也可先排序再判断两个string是否相等
class Solution {
public:
    bool isAnagram(string s, string t) {
        int a[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            a[s[i]-'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            a[t[i]-'a']--;
            if (a[t[i]-'a'] < 0) return false;
        }
        for (int i = 0; i < 26; i++) {
            if (a[i] != 0) return false;
        }
        return true;
    }
};