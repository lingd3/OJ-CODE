/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/copy-list-with-random-pointer
@Language: C++
@Datetime: 17-03-05 09:23
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        if (head == NULL) return NULL;
        if (head->next == NULL) {
            RandomListNode *temp = new RandomListNode(head->label);
            return temp;
        }
        // 复制节点
        RandomListNode *temp = head;
        while (temp != NULL) {
            RandomListNode *temp1 = new RandomListNode(temp->label);
            temp1->next = temp->next;
            temp->next = temp1;
            temp = temp1->next;
        }
        // 处理random
        temp = head;
        while (temp != NULL) {
            RandomListNode *temp1 = temp->next;
            if (temp->random != NULL) temp1->random = temp->random->next;
            temp = temp1->next;
        }
        //拆链表
        temp = head;
        RandomListNode *temp2 = temp->next;
        RandomListNode *temp1 = temp2;
        while (temp1->next != NULL) {
            temp->next = temp1->next;
            temp = temp->next;
            temp1->next = temp->next;
            temp1 = temp1->next;
        }
        return temp2;
    }
};
















