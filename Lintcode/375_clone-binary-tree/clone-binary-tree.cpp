/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/clone-binary-tree
@Language: C++
@Datetime: 17-03-11 07:33
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree
     * @return root of new tree
     */
    TreeNode* cloneTree(TreeNode *root) {
        // Write your code here
        if (root == NULL) return NULL;
        TreeNode* r = new TreeNode(root->val);
        if (root->left != NULL) r->left = cloneTree(root->left);
        if (root->right != NULL) r->right = cloneTree(root->right);
        return r;
    }
};