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
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int count = 0, childCount = 0;
        vector<int> a;
        vector<vector<int>> b;
        queue<TreeNode*> q;
        if (root == NULL) return b;
        a.push_back(root->val);
        q.push(root);
        count++;
        b.push_back(a);
        a.pop_back();
        while (!q.empty()) { //用count和childCount来区分每一层
            TreeNode* temp = q.front();
            q.pop();
            count--;
            if (temp->left != NULL) {
                q.push(temp->left);
                a.push_back(temp->left->val);
                childCount++;
            }
            if (temp->right != NULL) {
                q.push(temp->right);
                a.push_back(temp->right->val);
                childCount++;
            }
            if (count == 0 && a.size() > 0) {
                b.insert(b.begin()+0, a);
                while (!a.empty()) a.pop_back();
                count = childCount;
                childCount = 0;
            }
        }
        return b;
    }
};
//之前想得太复杂了，重写了一个简单点的
vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> a;
    queue<TreeNode*> q;
    if (root == NULL) return a;
    q.push(root);
    while (!q.empty()) {
        vector<int> b;
        int count = q.size();
        while (count--) {
            TreeNode* temp = q.front();
            q.pop();
            b.push_back(temp->val);
            if (temp->left != NULL) q.push(temp->left);
            if (temp->right != NULL) q.push(temp->right);
        }
        a.insert(a.begin()+0, b);
    }
    return a;
}


