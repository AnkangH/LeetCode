/*
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
你应当保留两个分区中每个节点的初始相对位置。
示例:
输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-list
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* preHead=new ListNode(1);//新链表前半部分的头
        ListNode* pre=preHead;//伪头 用于添加新节点
        ListNode* lastHead=new ListNode(1);//新链表后半部分的头
        ListNode* last=lastHead;//伪头 用于添加新节点
        while(head!=nullptr)//遍历原链表
        {
            if(head->val<x)//小于目标值的节点
            {
                pre->next=new ListNode(head->val);//放到前半部分
                pre=pre->next;//更新前半部分链表的当前节点
            }
            else//大于等于目标值的节点
            {
                last->next=new ListNode(head->val);//放到后半部分
                last=last->next;//更新后半部分链表的当前节点
            }
            head=head->next;//更新原链表当前节点
        }
        pre->next=lastHead->next;//连接前半部分与后半部分 注意跳过新建时无用的节点
        return preHead->next;//跳过新创建时的无用节点
    }
};
