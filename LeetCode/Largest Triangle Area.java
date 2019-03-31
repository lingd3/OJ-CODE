	public double largestTriangleArea(int[][] points) {
        int len = points.length;
        double rtn = -1;
		for (int i = 0; i < len; i++) {
			int x1 = points[i][0];
			int y1 = points[i][1];
			for (int j = i+1; j < len; j++) {
				int x2 = points[j][0];
				int y2 = points[j][1];
				for (int k = j+1; k < len; k++) {
					int x3 = points[k][0];
					int y3 = points[k][1];
					double area = Math.abs((x1-x3)*(y2-y3)-(x2-x3)*(y1-y3))*1.0/2;
					if (area > rtn) rtn = area;
				}
			}
		}
		return rtn;
    }