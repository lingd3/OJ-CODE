/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

public class Solution {
	/*
	 * @param head: a ListNode
	 * 
	 * @return: a ListNode
	 */
	public ListNode swapPairs(ListNode head) {
		if (head == null || head.next == null)
			return head;
		ListNode t = head.next;
		head.next = t.next;
		t.next = head;
		head = t;

		ListNode temp = head.next;
		ListNode temp2 = temp.next;
		while (temp2 != null && temp2.next != null) {
			temp.next = temp2.next;
			temp2.next = temp2.next.next;
			temp.next.next = temp2;
			temp = temp2;
			temp2 = temp2.next;
		}
		return head;
	}

}