/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/binary-tree-maximum-node
@Language: C++
@Datetime: 17-03-25 03:56
*/

class Solution {
public:
    /**
     * @param root the root of binary tree
     * @return the max node
     */
    TreeNode* maxNode(TreeNode* root) {
        // Write your code here
        if (root == NULL) return root;
        TreeNode* leftMax = root;
        TreeNode* rightMax = root;
        if (root->left != NULL) leftMax = maxNode(root->left);
        if (root->right != NULL) rightMax = maxNode(root->right);
        TreeNode* max = root;
        if (leftMax->val > max->val) max = leftMax;
        if (rightMax->val > max->val) max = rightMax;
        return max;
    }
    
    
};