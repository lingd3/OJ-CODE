/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/binary-tree-path-sum
@Language: C++
@Datetime: 17-03-05 06:33
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
     * @param root the root of binary tree
     * @param target an integer
     * @return all valid paths
     */
    vector<vector<int>> V;
    vector<vector<int>> binaryTreePathSum(TreeNode *root, int target) {
        // Write your code here
        vector<int> v;
        if (root == NULL) return V;
        int sum = 0;
        find(root, target, v, sum);
        return V;
    }
    
    void find(TreeNode *root, int target, vector<int> v, int sum) {
        v.push_back(root->val);
        sum += root->val;
        if (sum == target && root->left == NULL && root->right == NULL) {
            V.push_back(v);
        }
        if (root->left != NULL) {
            find(root->left, target, v, sum);
        }
        if (root->right != NULL) {
            find(root->right, target, v, sum);
        }
        sum -= root->val;
        v.pop_back();
    }
    
};

