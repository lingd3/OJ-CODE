class MyHashSet {

    private int[] val;

    /** Initialize your data structure here. */
    public MyHashSet() {
        val = new int[1000000];
    }
    
    public void add(int key) {
        val[key] = 1;
    }
    
    public void remove(int key) {
        val[key] = 0;
    }
    
    /** Returns true if this set contains the specified element */
    public boolean contains(int key) {
        if (val[key] == 0) return false;
        return true;
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */