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
public: //先用深度优先搜索遍历节点，在建树，不过效率很低。用递归反而更快更简单
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        stack<TreeNode*> s;
        queue<TreeNode*> q;
        s.push(root);
        while (!s.empty()) {
            TreeNode* temp = s.top();
            s.pop();
            q.push(temp);
            if (temp->right != NULL) s.push(temp->right);
            if (temp->left != NULL) s.push(temp->left);
        }
        q.pop();
        root->left = NULL;
        root->right = NULL;
        TreeNode* temp1 = root;
        while (!q.empty()) {
            TreeNode* temp = q.front();
            temp1->right = temp;
            temp1 = temp;
            temp1->left = NULL;
            q.pop();
        }
    }
};