/*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
示例：
给定一个链表: 1->2->3->4->5, 和 n = 2.
当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：
给定的 n 保证是有效的。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;//快指针 到达链表尾
        ListNode* cur=head;//当前指针 最后停在链表倒数第n个节点
        ListNode* pre=head;//当前指针的前驱指针
        int cntFast=0;//记录快指针移动次数
        int cntCur=0;//记录当前指针移动次数
        while(fast!=nullptr)
        {
            fast=fast->next;//快指针移动
            if(cntCur>=1)//当前指针移动一次之后 前驱指针开始移动
                pre=pre->next;
            if(cntFast>=n)//快指针移动n次之后 当前指针开始移动
            {
                cur=cur->next;
                cntCur++;
            }
            cntFast++;
        }
        if(cur==head)//说明cur在链表头 此时没有前驱节点
            return head->next;//删除当前节点即返回当前节点之后的链表
        else//否则cur有前驱节点 将前驱节点的下个节点指向cur的后驱节点即可
        {
            pre->next=cur->next;
            return head;
        }
    }
};
