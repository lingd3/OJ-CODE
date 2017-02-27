/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/construct-binary-tree-from-inorder-and-postorder-traversal
@Language: C++
@Datetime: 17-02-26 08:51
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
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
public:

    TreeNode *construct(vector<int> &inorder, vector<int> &postorder, 
        int is, int ie, int ps, int pe) {
            TreeNode * root = new TreeNode(postorder[pe]);
            if (ps == pe) return root;
            int i;
            for (i = 0; i < ie; i++) {
                if (inorder[i] == root->val) break;
            }
            if (i-1 >= is) {
                root->left = construct(inorder, postorder, is, i-1, ps, ps+i-1-is);
            }
            if (i+1 <= ie) {
                root->right = construct(inorder, postorder, i+1, ie, ps+i-is, pe-1);
            }
            return root;            
        }


    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // write your code here
        if (inorder.empty() || postorder.empty() || 
            inorder.size() != postorder.size()) return NULL;
        return construct(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
};