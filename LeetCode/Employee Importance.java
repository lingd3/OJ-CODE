/*
// Employee info
class Employee {
    // It's the unique id of each node;
    // unique id of this employee
    public int id;
    // the importance value of this employee
    public int importance;
    // the id of direct subordinates
    public List<Integer> subordinates;
};
*/
class Solution {
    public int getImportance(List<Employee> employees, int id) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(id);
        int sum = 0;
		while (!queue.isEmpty()) {
			int i = queue.poll();
			for (Employee e : employees) {
				if (e.id == i) {
					sum += e.importance;
					List<Integer> subordinates = e.subordinates;
					queue.addAll(subordinates);
				}
			}
		}
		return sum;
    }
}