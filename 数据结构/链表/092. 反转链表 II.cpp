/*
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
说明:
1 ≤ m ≤ n ≤ 链表长度。
示例:
输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list-ii
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* cur=head;//当前节点 遍历原链表
        ListNode* resTail=head;//如果不是从1开始反转 那么记录反转的起点 用于连接反转链表
        ListNode* pre=nullptr;//头插法 反转链表部分的当前头
        ListNode* preTail=nullptr;//反转链表部分的尾 用于连接剩余节点
        int i=1;//计数起点
        while(cur!=nullptr)//遍历原链表
        {
            if(i>=m)//达到反转链表的起点
            {
                while(i<=n)//反转m-n位置链表
                {
                    ListNode* nxt=cur->next;//保存当前节点的下个节点 防止修改后无法继续遍历原链表
                    cur->next=pre;//头插法反转
                    pre=cur;//当前头移动
                    if(i==m)
                        preTail=pre;//第一个反转的链表节点会成为反转链表的尾 记录该位置
                    cur=nxt;//继续遍历原链表
                    i++;//计数更新
                }
                preTail->next=cur;//反转m-n位置链表后 将反转链表的尾连接到n+1位置
                if(m>1)
                    resTail->next=pre;//若不是从第一个开始反转 那么前面未反转的链表的尾要连接到反转链表的头
                break;//退出循环
            }
            resTail=cur;//未到达m位置的节点保存为前部分的尾节点
            cur=cur->next;//向后遍历
            i++;//计数增加
        }
        if(m==1)
            return pre;//若从原链表第一个节点开始反转 返回反转链表的头
        else
            return head;//否则 返回原链表头
    }
};
