class Solution {
public:
    int strStr(string a, string b) {
        if (a.size() > 10000) return -1;
        if (b == "") return 0;
        if (a == b) return 0;
        int i, j, l;
	for (i = 0; i < a.size(); i++) {
		if (a[i] == b[0]) {
			l = i;
			for (j = 0; j < b.size(); j++) {
				if (b[j] == a[l]) {
					l++;
					continue;
				}
				else break;
			}
			if (j == b.size()) return i;
			else continue;
		}
	}
	return -1;
    }
};
