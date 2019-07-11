/*
删除链表中等于给定值 val 的所有节点。
示例:
输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr)
            return head;//预处理 空链表直接返回
        ListNode* res=head;//返回值的头
        while(res!=nullptr)
        {
            if(res->val==val)
                res=res->next;//找打第一个不等于val的节点作为返回值的头
            else
                break;
        }
        if(res==nullptr)
            return res;//防止全删除的情况 下面访问next会非法
        ListNode* pre=res;//记录前节点
        ListNode* cur=pre->next;//当前节点 从返回值的头开始遍历
        while(cur!=nullptr)//向后遍历
        {
            if(cur->val==val)//跳过等于val的节点
                while(cur!=nullptr&&cur->val==val)
                    cur=cur->next;
            pre->next=cur;//连接前节点和当前节点
            pre=cur;//更新前节点
            if(cur!=nullptr)//当前节点不是链表尾
                cur=cur->next;//更新当前节点继续向后遍历
        }
        return res;
    }
};
