/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		int carry = 0;
		ListNode l = new ListNode(0);
		ListNode t = l;
		while (l1 != null && l2 != null) {
			int s = l1.val+l2.val+carry;
			if (s < 10) {
				t.next = new ListNode(s);
				carry = 0;
				t = t.next;
			}
			else {
				t.next = new ListNode(s-10);
				carry = 1;
				t = t.next;
			}
            l1 = l1.next;
            l2 = l2.next;
		}
		ListNode m = null;
		if (l1 == null) m = l2;
		else if (l2 == null) m = l1;
		while (m != null) {
			int s = m.val+carry;
			if (s < 10) {
				t.next = new ListNode(s);
				carry = 0;
				t = t.next;
			}
			else {
				t.next = new ListNode(s-10);
				carry = 1;
				t = t.next;
			}
            m = m.next;
		}
		if (carry == 1) t.next = new ListNode(1);
        l = l.next;
		return l;
    }
}