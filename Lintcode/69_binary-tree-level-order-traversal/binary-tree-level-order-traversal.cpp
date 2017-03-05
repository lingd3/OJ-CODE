/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/binary-tree-level-order-traversal
@Language: C++
@Datetime: 17-02-28 13:37
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
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        // write your code here
        queue<TreeNode*> q;
        int count = 0;
        vector<int> v;
        vector<vector<int>> v2;
        if (root == NULL) return v2;
        q.push(root);
        count++;
        int count2 = 1;
        while (!q.empty()) {
            count = count2;
            count2 = 0;
            v.clear();
            for (int i = 0; i < count; i++) {
                TreeNode * top = q.front();
                v.push_back(top->val);
                if (top->left != NULL) {
                    q.push(top->left);
                    count2++;
                }
                if (top->right != NULL) {
                    q.push(top->right);
                    count2++;
                }
                q.pop();
            }
            v2.push_back(v);
        }
        return v2;
    }
};

