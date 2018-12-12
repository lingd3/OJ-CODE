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
    public TreeNode increasingBST(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        inorder(root, list);
        TreeNode node = new TreeNode(list.get(0));
        TreeNode temp = node; 
        for (int i = 1; i < list.size(); i++) {
        	temp.right = new TreeNode(list.get(i));
        	temp = temp.right;
        }
		return node;
    }

	private void inorder(TreeNode root, List<Integer> list) {
		if (root == null) return;
		if (root.left != null) inorder(root.left, list);
		list.add(root.val);
		if (root.right != null) inorder(root.right, list);
	}
}