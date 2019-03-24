/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val,List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>> rtn = new ArrayList<>();
    	if (root == null) return rtn;
    	Queue<List<Node>> q = new LinkedList<>();
    	List<Node> list = new ArrayList<>();
    	list.add(root);
    	q.add(list);
    	while (!q.isEmpty()) {
    		List<Integer> vals = new ArrayList<>();
    		List<Node> front = new ArrayList<>();;
    		while (!q.isEmpty()) {
    			front.addAll(q.poll());
    		}
    		for (Node n : front) {
    			vals.add(n.val);
    			if (n.children.size() > 0) q.add(n.children);
    		}
    		rtn.add(vals);
    	}
    	return rtn;
    }
}