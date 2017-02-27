/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/construct-binary-tree-from-preorder-and-inorder-traversal
@Language: C++
@Datetime: 17-02-25 08:31
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
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:

    TreeNode *construct(vector<int> &preorder, vector<int> &inorder, int ps, 
        int pe, int is, int ie) {
            TreeNode * root = new TreeNode(preorder[ps]);
            if (ps == pe) return root;
            int i;
            for (i = 0; i < ie; i++) {
                if (inorder[i] == root->val) break;
            }
            if (is <= i-1) 
                root->left = construct(preorder, inorder, 
                    ps+1, ps+(i-is), is, i-1);
            if (i+1 <= ie) 
                root->right = construct(preorder, inorder,
                    ps+(i-is)+1, pe, i+1, ie);
            return root;
        }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty() || inorder.empty() || 
            preorder.size() != inorder.size()) return NULL;
        return construct(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};





