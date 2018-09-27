/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode middleNode(ListNode head) {
		if (head == null || head.next == null) return head;
        ListNode temp1 = head, temp2 = head;
        while (temp2.next != null && temp2.next.next != null) {
        	temp1 = temp1.next;
        	temp2 = temp2.next.next;
        }
        if (temp2.next != null) temp1 = temp1.next;
		return temp1;
    }
}