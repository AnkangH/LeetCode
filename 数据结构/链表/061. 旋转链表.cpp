/*
给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
示例 1:
输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
示例 2:
输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-list
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr)
            return head;//预判断 边界条件 空指针直接返回 通常若边界条件不满足判断逻辑 写成分段函数的形式 
        ListNode* tail=head;//当前头
        int n=1;//节点总数
        while(tail->next!=nullptr)
        {
            tail=tail->next;//当前头移动
            n++;//计数增加
        }
        k=k%n;//k整除n时，链表复原 因此移动k%n取余次即可
        for(int i=0;i<n-k;i++)//通过判断 右移k次即头节点向后移k次，同时将头结点作为尾结点
        {
            tail->next=new ListNode(head->val);//以当前头结点作为尾结点
            tail=tail->next;//尾结点移动
            head=head->next;//头结点移动
        }
        return head;//返回头结点即可
    }
};
