class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if (s.size() <= 1) return false;
        int d = s.size();
        for (int i = 1; i < d/2+1; i++) {
            string a = s.substr(0, i);
            int count = 1;
            for (int j = i; j+a.size() <= d; j = j+a.size()) {
                if (a == s.substr(j, i)) count++;
                else break;
            }
            if (count * a.size() == d) return true;
        }
        return false;
    }
};