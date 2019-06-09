class Solution {
    class Temp {
    	int dis;
        int x;
        int y;
        public Temp(int a, int b, int c) {
            dis = a;
            x = b;
            y = c;
        }
    }
    
    public int[][] allCellsDistOrder(int R, int C, int r0, int c0) {
        int[][] rtn = new int[R*C][2];
        List<Temp> list = new ArrayList<>();
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                int dis = Math.abs(i-r0)+Math.abs(j-c0);
                list.add(new Temp(dis, i, j));
            }
        }
        list.sort(new Comparator<Temp>() {
            @Override
            public int compare(Temp t1, Temp t2) {
                return t1.dis-t2.dis;
            }
        });
        int k = 0;
        for (Temp t : list) {
            rtn[k][0] = t.x;
            rtn[k][1] = t.y;
            k++;
        }
        return rtn;
    }
}