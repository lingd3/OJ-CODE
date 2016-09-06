class Solution {
public:
    //最简单的做法，也可先排序再遍历
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    a.push_back(nums1[i]);
                    nums2[j] = -100000;
                    break;
                }
            }
        }
        return a;
    }
};