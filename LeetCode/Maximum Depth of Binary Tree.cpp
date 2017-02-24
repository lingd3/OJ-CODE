/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//找到二叉树的最大深度
//用递归
class Solution {
public:
    //DFS思想，利用递归
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return left>right? 1+left:1+right;
    }
    
    //BFS思想，利用队列
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        queue<TreeNode*> q;
        int count = 1;
        int depth = 0;
        q.push(root);
        while (!q.empty()) {
            TreeNode *temp = q.front();
            q.pop();
            count--;
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
            
            if (count == 0) { //每一层遍历完后深度加一
                depth++;
                count = q.size();
            }
        }
        return depth;
    }
};


