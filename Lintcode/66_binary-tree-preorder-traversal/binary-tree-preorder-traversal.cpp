/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/binary-tree-preorder-traversal
@Language: C++
@Datetime: 17-03-11 07:45
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
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> v;
        if (root == NULL) return v;
        stack<TreeNode*> s;
        TreeNode* temp = root;
        while (temp != NULL || !s.empty()) {
            while (temp != NULL) {
                v.push_back(temp->val);
                s.push(temp);
                temp = temp->left;
            }
            if (!s.empty()) {
                temp = s.top();
                s.pop();
                temp = temp->right;
            }
        }
        return v;
    }
};






