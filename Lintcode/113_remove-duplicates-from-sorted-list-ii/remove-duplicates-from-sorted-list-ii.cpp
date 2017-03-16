/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/remove-duplicates-from-sorted-list-ii
@Language: C++
@Datetime: 17-03-14 06:36
*/

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        // write your code here
        if (head == NULL || head->next == NULL) return head;
        //消除头部重复的元素
        head = deleteHead(head);
        if (head == NULL || head->next == NULL) return head;
        //消除中间重复的元素
        ListNode *temp = head;
        ListNode *temp1 = head->next;
        while (temp1 != NULL && temp1->next != NULL) {
            if (temp1->val == temp1->next->val) {
                temp->next = NULL;
                temp->next = deleteHead(temp1);
            }
            temp = temp->next;
            temp1 = NULL;
            if (temp != NULL) temp1 = temp->next;
        }
        return head;
    }
    
    ListNode * deleteHead(ListNode *head) {
        while (head != NULL && head->next != NULL && head->val == head->next->val) {
            ListNode *temp = head;
            while (temp != NULL && temp->next != NULL && temp->val == temp->next->val) {
                temp = temp->next;
            } 
            ListNode *temp1 = head;
            head = temp->next;
            temp->next = NULL;
            delete temp1;
        }
        return head;
    }
    
};













