/*
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
示例:
输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-k-sorted-lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr;//预处理 
        ListNode* head=new ListNode(1);//合并后的链表头
        ListNode* p=head;//合并后的链表当前头
        int size=lists.size();
        while(!end(lists))//检测lists中的链表是否全为nullptr
        {
            int minIndex=INT_MAX;//记录当前最小值
            int minVal=INT_MAX;//记录最小值对应的链表在数组中的索引
            for(int i=0;i<size;i++)
            {
                if(lists[i]==nullptr)
                    continue;//跳过nullptr
                if(lists[i]->val<minVal)
                {
                    minVal=lists[i]->val;//更新最小值
                    minIndex=i;//更新对应索引
                }
            }
            if(minIndex!=INT_MAX)//根据最小值索引是否修改来判断当前状态
            {
                p->next=new ListNode(minVal);//合并后的链表当前节点
                lists[minIndex]=lists[minIndex]->next;//移动使用的链表节点
                p=p->next;//合并后的链表节点向后移动
            }
        }
        return head->next;//因为创建时多了一个节点 所以返回其后的链表
    }
    bool end(vector<ListNode*>& lists)//判断链表数组中是否全为nullptr 即链表都到达链表尾 合并完成
    {
        int size=lists.size();
        for(int i=0;i<size;i++)
            if(lists[i]!=nullptr)
                return false;
        return true;
    }
};
