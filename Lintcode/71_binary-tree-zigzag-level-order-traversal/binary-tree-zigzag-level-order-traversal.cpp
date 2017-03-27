/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/binary-tree-zigzag-level-order-traversal
@Language: C++
@Datetime: 17-03-21 09:11
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
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> vec;
        if (root == NULL) return vec;
        queue<TreeNode*> q;
        q.push(root);
        bool r = false;
        while (!q.empty()) {
            int count = q.size();
            vector<int> v;
            while (count--) {
                TreeNode *temp = q.front();
                v.push_back(temp->val);
                q.pop();
                if (temp->left != NULL) q.push(temp->left);
                if (temp->right != NULL) q.push(temp->right);
            }
            if (r) {
                vector<int> v1;
                for (int i = v.size()-1; i >= 0; i--) {
                    v1.push_back(v[i]);
                }
                vec.push_back(v1);
            }
            else vec.push_back(v);
            r = !r;
        }
        return vec;
    }
};




