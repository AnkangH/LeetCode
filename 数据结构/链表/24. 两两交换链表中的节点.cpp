/*
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
示例:
给定 1->2->3->4, 你应该返回 2->1->4->3.
*/

//迭代交换法
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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr)
            return head;
        ListNode* preHead=new ListNode(0);//前驱节点头
        preHead->next=head;//前驱节点连接到链表头
        ListNode* pre=preHead;//前驱节点的假头（需要移动）
        while(head!=nullptr)
        {
            if(head->next==nullptr)
                break;//链表个数为奇数时 最后一个不执行操作
            ListNode* nxt=head->next;//保存当前节点的后驱节点
            head->next=head->next->next;//断链 修改当前节点的后驱节点
            pre->next=nxt;//修改当前节点的前驱节点
            nxt->next=head;//修改后驱节点的指向
            pre=head;//前驱节点移动
            head=head->next;//当前节点移动
        }
        return preHead->next;//返回创建的前驱节点头的下一个节点
    }
};
