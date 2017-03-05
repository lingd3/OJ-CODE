/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/binary-tree-postorder-traversal
@Language: C++
@Datetime: 17-02-28 14:12
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
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> v;
        stack<TreeNode*> s;
        TreeNode * curr = root;
        TreeNode * previsited = NULL;
        while (curr != NULL || !s.empty()) {
            while (curr != NULL) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            // 当前节点的右孩子如果为空或者已经被访问，则访问当前节点
            if (curr->right == NULL || curr->right == previsited) {
                v.push_back(curr->val);
                previsited = curr;
                s.pop();
                curr = NULL;
            }
            else curr = curr->right; //否则访问右孩子
        }
        return v;
    }
};


