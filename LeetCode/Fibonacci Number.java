    public int fib(int N) {
        if (N == 0 || N == 1) return N;
        int result = 0, a = 0, b = 1;
        for (int i = 2; i <= N; i++) {
        	result = a + b;
        	a = b;
        	b = result;
        }
        return result;
    }