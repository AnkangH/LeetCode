/*
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
说明：不允许修改给定的链表。
示例 1：
输入：head = [3,2,0,-4], pos = 1
输出：tail connects to node index 1
解释：链表中有一个环，其尾部连接到第二个节点。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


//哈希表解法
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* p=head;
        unordered_map<ListNode*,bool> m;//哈希表解法
        while(p!=nullptr)//遍历链表
        {
            if(m.count(p)==0)
                m[p]=true;//第一次出现
            else
                break;//第一个重复的节点为环的入口
            p=p->next;//下个节点
        }
        return p;
    }
};


//双指针解法
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *f=head,*s=head;//快慢指针
        while(f!=nullptr&&f->next!=nullptr)//判断是否有环循环条件
        {
            f=f->next->next;//快指针每次走两步
            s=s->next;//慢指针每次走一步
            if(f==s)//有环
            {
                s=head;//慢指针从头节点出发
                while(f!=s)//找环的入口
                {
                    s=s->next;//慢指针每次走一步
                    f=f->next;//快指针每次走一步
                }
                return f;//返回环的入口
            }
        }
        return nullptr;//没有环
    }
};
