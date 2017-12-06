/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    /**
     * @param head: the List
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    public ListNode rotateRight(ListNode head, int k) {
            if (head == null || head.next == null || k == 0) return head;
            int length = 0;
            ListNode temp = head;
            while (temp != null) {
                    length++;
                    temp = temp.next;
            }
            k %= length;
            if (k == 0) return head;
            
            temp = head;
            int c = 1;
            while (c < length-k) {
                    temp = temp.next;
                    c++;
            }
            ListNode temp2 = temp.next;
            temp.next = null;
            ListNode temp3 = temp2;
            while (temp3.next != null) {
                    temp3 = temp3.next;
            }
            temp3.next = head;
            head = temp2;
            return head;
    }
    
}