class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> v;
        if (s == "") return v;
        int d1 = s.size(), d2 = p.size();
        int q[26] = {0};
        for (int i = 0; i+d2 <= d1; i++) {
            for (int j = 0; j < d2; j++) {
                q[p[j]-'a']++;
            }
            int k = i;
            for (int l = 0; l < d2; l++) {
                q[s[k]-'a']--;
                k++;
            }
            for (k = 0; k < 26; k++) {
                if (q[k] != 0) break;
            }
            if (k == 26) v.push_back(i);
            for (int k = 0; k < 26; k++) q[k] = 0;
        }
        return v;
    }
};