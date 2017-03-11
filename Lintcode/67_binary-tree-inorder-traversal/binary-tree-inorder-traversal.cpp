/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/binary-tree-inorder-traversal
@Language: C++
@Datetime: 17-03-11 07:50
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
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> v;
        if (root == NULL) return v;
        stack<TreeNode*> s;
        TreeNode *temp = root;
        while (temp != NULL || !s.empty()) {
            while (temp != NULL) {
                s.push(temp);
                temp = temp->left;
            }
            if (!s.empty()) {
                temp = s.top();
                s.pop();
                v.push_back(temp->val);
                temp = temp->right;
            }
        }
        return v;        
    }
};







