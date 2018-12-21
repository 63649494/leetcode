/* 给定一个链表，判断链表中是否有环。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

 

示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。


示例 2：

输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。


示例 3：

输入：head = [1], pos = -1
输出：false
解释：链表中没有环。


 

进阶：

你能用 O(1)（即，常量）内存解决此问题吗？ */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
     struct ListNode * fast;
     struct ListNode * slow;
        
        if(head == NULL || head -> next == NULL)
            return false;
        else{
            fast = head -> next;
            slow = head;
            while(fast != NULL){
                if(fast == slow)
                    return true;
                else{
                    fast = fast -> next;
                    if(fast == NULL)
                        return false;
                    else{
                        fast = fast -> next;
                        slow = slow -> next;
                    }
                }
            }
            return false;
    }
}
/*思路是这样的：

设置两个指针，fast和slow，fast每次走两步，slow每次走一步，想象一下，如果链表有环是封闭的话，两个指针在里面就形成了一个追击问题，是早晚会相遇的，我们就依据这一思路来做题。
*/