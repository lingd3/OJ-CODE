//也可先排序，再用两个指针遍历或者用二分查找来实现
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        set<int> nums;
        if (len1 <= len2) {
            for (int i = 0; i < len1; i++) {
                for (int j = 0; j < len2; j++) {
                    if (nums1[i] == nums2[j]) {
                        nums.insert(nums1[i]);
                    }
                }
            }
        }
        else {
            for (int i = 0; i < len2; i++) {
                for (int j = 0; j < len1; j++) {
                    if (nums2[i] == nums1[j]) {
                        nums.insert(nums2[i]);
                    }
                }
            }
        }
        vector<int> v;
        set<int>::iterator it;
        for (it = nums.begin(); it != nums.end(); it++) {
            v.push_back(*it);
        }
        return v;
    }
};