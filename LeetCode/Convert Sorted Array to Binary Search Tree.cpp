/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BuildTree(nums, 0, nums.size()-1);
    }
    
    TreeNode* BuildTree(vector<int>& nums, int start, int end) {
        if (start > end) return NULL;
        if (start == end) return new TreeNode(nums[start]);
        int mid = (start+end)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = BuildTree(nums, start, mid-1);
        node->right = BuildTree(nums, mid+1, end);
        return node;
    }
    
};