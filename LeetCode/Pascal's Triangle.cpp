class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        if (numRows == 0) return v;
        vector<int> a;
        a.push_back(1);
        v.push_back(a);
        if (numRows == 1) return v;
        for (int i = 1; i < numRows; i++) {
            vector<int> b;
            vector<int> c = v[i-1];
            for (int j = 0; j < i+1; j++) {
                if (j == 0 || j == i) b.push_back(1);
                else {
                    b.push_back(c[j-1]+c[j]);
                }
            }
            v.push_back(b);
        }
        return v;
    }
};