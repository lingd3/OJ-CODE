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
	 public List<Double> averageOfLevels(TreeNode root) {
		 List<Double> list = new ArrayList<>();
		 if (root == null) return list;
		 Queue<TreeNode> q = new LinkedList<>();
		 q.add(root);
		 int t = 1;
		 while (!q.isEmpty()) {
             t = q.size();
			 double d = 0;
			 int k = 0;
			 while (t > 0) {
				 TreeNode temp = q.poll();
				 if (temp.left != null) q.add(temp.left);
				 if (temp.right != null) q.add(temp.right);
				 d += temp.val;
				 k++;
                 t--;
			 }
			 list.add(d/k);
			 
		 }
		 return list;
	 }
}