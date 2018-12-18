/* 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？ */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *p1, *p2, *pre;
        if ( head == NULL || n <= 0 ) {
            return NULL;
        }   //空链表则返回null
        p1 = head;
        p2 = head;
        for ( int i = 0; i < n-1; i++ ) {
            if ( p1 -> next != NULL ) {
                p1 = p1 -> next;
            } else {
                return NULL;
            }
        }
        while ( p1 -> next != NULL ) {
            p1 = p1 -> next;
            pre = p2;        //关键一步：标记倒数第n个节点的前一个节点
            p2 = p2 ->next;
        }
        if ( p2 == head ) {  //关键判断：如果只有一个节点，倒数第n个就是第一个，删除后链表为空
            head = head -> next;
        } else {
        pre ->next = pre -> next -> next;
        }
        return head;
    }
