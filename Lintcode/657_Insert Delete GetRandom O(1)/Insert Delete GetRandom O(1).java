public class RandomizedSet {
    
    private List<Integer> nums;
    
    private Map<Integer, Integer> map;

    public RandomizedSet() {
        nums = new ArrayList<Integer>();
        map = new HashMap<Integer, Integer>();
    }
    
    // Inserts a value to the set
    // Returns true if the set did not already contain the specified element or false
    public boolean insert(int val) {
            if (map.containsKey(val)) return false;
            nums.add(val);
            map.put(val, nums.size()-1);
            return true;
    }
    
    // Removes a value from the set
    // Return true if the set contained the specified element or false
    public boolean remove(int val) {
            if (!map.containsKey(val)) return false;
            int lastVal = nums.get(nums.size()-1);
            if (val != lastVal) {
                    int index = map.get(val);
                    nums.set(index, lastVal);
                    map.put(lastVal, index);
            }
            nums.remove(nums.size()-1);
            map.remove(val);
            return true;
    }
    
    // Get a random element from the set
    public int getRandom() {
            return nums.get((int)(Math.random()*nums.size()));
    }
    
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param = obj.insert(val);
 * boolean param = obj.remove(val);
 * int param = obj.getRandom();
 */