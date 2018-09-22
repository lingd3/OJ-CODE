/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode searchBST(TreeNode root, int val) {
        if (root == null) return null;
        TreeNode rtn = root;
        while (rtn != null) {
            if (rtn.val == val) return rtn;
            else if (rtn.val > val) rtn = rtn.left;
            else rtn = rtn.right;
        }
        return null;
    }
}