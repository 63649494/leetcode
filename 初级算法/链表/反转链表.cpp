/* 反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？ */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
//Node * Node_reverse_v2(Node* node) {
    if (head == NULL) return NULL;
    if (head->next == NULL) return head;

    struct ListNode *first = head; //总是指向新链表的首部。
    struct ListNode *now = head->next;
    struct ListNode *next = now->next;
    first->next = NULL; //首节点变成尾节点，尾节点的下一个节点置空，防止环路。
    do {
        next = now->next;
        now->next = first;
        first = now;
        now = next;
    } while (next != NULL);

    return first;
}