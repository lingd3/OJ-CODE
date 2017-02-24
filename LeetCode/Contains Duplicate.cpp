//beats 97.93% of cppsubmissions !!!
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() <= 1) return false;
        int a[1000000] = {0};
        for (int i = 0; i < nums.size(); i++) {
            a[nums[i]]++;
            if (a[nums[i]] > 1) return true;
        }
        return false;
    }
};