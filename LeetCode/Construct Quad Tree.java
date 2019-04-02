/*
// Definition for a QuadTree node.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;

    public Node() {}

    public Node(boolean _val,boolean _isLeaf,Node _topLeft,Node _topRight,Node _bottomLeft,Node _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
    public Node construct(int[][] grid) {
        int a = grid.length;
        int b = grid[0].length;
        return construct2(grid, 0, b, 0, a);
    }

    
    private Node construct2(int[][] grid, int c1, int c2, int r1, int r2) {
        Node root = null;
        int t = grid[r1][c1];
        int i = r1, j = c1;
        for (i = r1; i < r2; i++) {
            for (j = c1; j < c2; j++) {
                if (grid[i][j] != t) {
                    Node _topLeft = construct2(grid, c1, (c1+c2)/2, r1, (r1+r2)/2);
                    Node _topRight = construct2(grid, (c1+c2)/2, c2, r1, (r1+r2)/2);
                    Node _bottomLeft = construct2(grid, c1, (c1+c2)/2, (r1+r2)/2, r2);
                    Node _bottomRight = construct2(grid, (c1+c2)/2, c2, (r1+r2)/2, r2);
                    root = new Node(false, false, _topLeft, _topRight, _bottomLeft, _bottomRight);
                    return root;
                }
            }
        }
        root = new Node();
        root.isLeaf = true;
        if (t == 0) root.val = false;
        else root.val = true;
        return root;
    }
}