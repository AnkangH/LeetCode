/*
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
示例 1:
输入: 1->2->3->3->4->4->5
输出: 1->2->5
示例 2:
输入: 1->1->1->2->3
输出: 2->3
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr||head->next==nullptr)//因为逻辑或 先判断非空 再判断next
            return head;
        ListNode* resHead=new ListNode(1);//新链表头
        ListNode* res=resHead;//新链表伪头 用于添加节点
        ListNode* pre=head;//前节点
        ListNode* cur=head->next;//当前节点
        while(cur!=nullptr)
        {
            if(cur->val!=pre->val)//互异节点
            {
                res->next=new ListNode(pre->val);//添加新节点
                res=res->next;//新节点后移
                pre=cur;//前节点更新
                if(cur->next==nullptr)//边界条件 当cur为最后一个节点且满足时
                {
                    res->next=new ListNode(cur->val);//提前放入 防止遗漏最后一个节点
                    break;
                }
                cur=cur->next;//当前节点后移
            }
            else//重复节点
            {
                while(cur!=nullptr&&cur->val==pre->val)//注意cur越界 cur后移置不等于pre
                    cur=cur->next;
                if(cur==nullptr)//后面全都是重复元素
                    break;//退出
                if(cur->next==nullptr)//cur到达最后一个 且与pre不相等 则cur一定可以放入结果
                {
                    res->next=new ListNode(cur->val);
                    break;
                }
                pre=cur;//pre指向当前的cur 即不与pre相等的元素
                cur=cur->next;//cur指向后一个元素
            }
        }
        return resHead->next;//创建时多了一个节点 返回第二个节点开始的链表
    }
};
