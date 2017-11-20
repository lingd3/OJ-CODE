/**
 * Definition of TreeNode:
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left, right;
 *     public TreeNode(int val) {
 *         this.val = val;
 *         this.left = this.right = null;
 *     }
 * }
 */
public class Solution {
    /**
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> list = new ArrayList<String>();
        if (root != null) addPath(root, String.valueOf(root.val), list);
        return list;        
    }
    
    public void addPath(TreeNode node, String path, List<String> list) {
        if (node == null) return;
        if (node.left == null && node.right == null) list.add(path);
        if (node.left != null) addPath(node.left, path + "->" + String.valueOf(node.left.val), list);
        if (node.right != null) addPath(node.right, path + "->" + String.valueOf(node.right.val), list);
    }
    
}