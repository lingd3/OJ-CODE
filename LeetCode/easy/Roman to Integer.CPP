class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        map<char, int> m;
        m.insert(pair<char, int>('I', 1));
        m.insert(pair<char, int>('V', 5));
        m.insert(pair<char, int>('X', 10));
        m.insert(pair<char, int>('L', 50));
        m.insert(pair<char, int>('C', 100));
        m.insert(pair<char, int>('D', 500));
        m.insert(pair<char, int>('M', 1000));
        for (int i = 0; i < s.size(); i++) {
            if (i < s.size()-1 && m[s[i]] < m[s[i+1]]) {
                sum += (m[s[i+1]]- m[s[i]]);
                i++;
            }
            else {
                sum += m[s[i]];
            }
        }
        return sum;
    }
};