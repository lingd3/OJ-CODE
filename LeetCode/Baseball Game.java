class Solution {
    public int calPoints(String[] ops) {
		Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < ops.length; i++) {
        	if ("+".equals(ops[i])) {
        		int s1 = stack.pop();
        		int s2 = stack.peek();
        		stack.push(s1);
        		stack.push(s1+s2);
        	}
        	else if ("D".equals(ops[i])) {
        		int s = stack.peek();
        		stack.add(s*2);
        	}
        	else if ("C".equals(ops[i])) {
        		stack.pop();
        	}
        	else {
        		stack.push(Integer.valueOf(ops[i]));
        	}
        }
        int s = 0;
        while (!stack.isEmpty()) {
        	s += stack.pop();
        }
		return s;
    }
}