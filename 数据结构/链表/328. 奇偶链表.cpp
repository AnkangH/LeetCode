/*
给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。
示例 1:
输入: 1->2->3->4->5->NULL
输出: 1->3->5->2->4->NULL
示例 2:
输入: 2->1->3->5->6->4->7->NULL 
输出: 2->3->6->7->1->5->4->NULL
说明:

应当保持奇数节点和偶数节点的相对顺序。
链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。
*/


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr)
            return head;//访问head->next先判断其是否为nullptr
        ListNode* p1=head;//奇序节点
        ListNode* p2=head->next;//偶序节点
        ListNode* p2Head=head->next;//偶序节点的头节点 避免断链后重新找
        while(p1->next!=nullptr&&p2->next!=nullptr)//停止条件
        {
            p1->next=p1->next->next;//奇序节点的下个节点
            p2->next=p2->next->next;//偶序节点的下个节点
            p1=p1->next;//奇序节点后移
            p2=p2->next;//偶序节点后移
        }
        p1->next=p2Head;//奇序节点的最后一个节点连接到偶序节点的第一个节点
        return head;//返回链表头
    }
};
