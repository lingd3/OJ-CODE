class Solution {
public:
    string reverseString(string s) {
        if (s.empty()) return s;
    	string a;
    	for (int i = 0; i < s.size(); i++) {
    		a.insert(0, 1, s[i]);
    	}
        return a;
    }
};
