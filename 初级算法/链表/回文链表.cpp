/* 请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？ */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
        int lenth, i;
        struct ListNode *point1, *point2, *point3;
        point3 = point2 = head;
        point1 = NULL;
        lenth = 0;
        if(head == NULL || head->next == NULL)
            return true;
        while(point3 != NULL)//取得长度
        {
            point3 = point3->next;
            lenth++;
        }
        for(i = 0;i < (lenth / 2);i++)//遍历到中间，并逆置
        {
            point3 = point2->next;//回归第一个
            //逆置
            point2->next = point1;
            point1 = point2;
            point2 = point3;
        }
        if((lenth % 2) == 1)
            point3 = point3->next;
        while(point3 != NULL && point1 != NULL)//两个指针开始向两头移动，取值比较
        {
            if(point3->val != point1->val)
                return false;
            point3 = point3->next;
            point1 = point1->next;
        }
        return true;//比较中没有发现不同值，则为回文链表
    }