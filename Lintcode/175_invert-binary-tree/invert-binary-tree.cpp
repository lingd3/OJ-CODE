/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/invert-binary-tree
@Language: C++
@Datetime: 17-04-10 13:04
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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    /*递归实现
    void invertBinaryTree(TreeNode *root) {
        // write your code here
        if (root == NULL) return;
        swap(node -> left, node -> right);
        invertBinaryTree(root->left);
        invertBinaryTree(root->right);
    }*/
    
    //非递归实现    
    void invertBinaryTree(TreeNode *root) {
        if (root == NULL) return;
        queue<TreeNode*> level;
        level.push(root);
        while (!level.empty()) {
             TreeNode* node = level.front();
             level.pop();
             swap(node->left, node->right);
             if (node->left != NULL) level.push(node->left);
             if (node->right != NULL) level.push(node->right);
         }
    }
    
};