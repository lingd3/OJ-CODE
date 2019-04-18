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
	public int rangeSumBST(TreeNode root, int L, int R) {
        int sum = 0;
		Queue<TreeNode> q = new LinkedList<>();
		q.add(root);
		while (!q.isEmpty()) {
			TreeNode t = q.poll();
			if (t.left != null) q.add(t.left);
			if (t.right != null) q.add(t.right);
			if (t.val >= L && t.val <= R) sum += t.val;
		}
		return sum;
    }
}