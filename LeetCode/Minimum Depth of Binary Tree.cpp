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
public:	//递归
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if (left == 0) return 1+right; //注意这里需要判断
        if (right == 0) return 1+left;
        if (left <= right) return 1+left;
        else return 1+right;
    }
};

//bfs
int minDepth(TreeNode *root) {
    if(root == NULL) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int depth = 0;
    while(!q.empty()) {
        int sz = q.size();
        depth++;
        for(int i = 0; i < sz; i++) {
            TreeNode* temp = q.front();q.pop();
            if(temp != NULL && temp->left == NULL && temp->right == NULL){
                return depth;
            };
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
    return depth;
}