/*
编写一个程序，找到两个单链表相交的起始节点。
注意：
如果两个链表没有交点，返回 null.
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr||headB==nullptr)
            return nullptr;
        ListNode* pa=headA;
        ListNode* pb=headB;
        while(pa!=nullptr||pb!=nullptr)//走的次数一样 所以最后都停在nullptr
        {
            if(pa==pb)
                return pa;//判断是否相同 相同代表有交点
            if(pa==nullptr)
                pa=headB;
            else
                pa=pa->next;//每次pa只移动一次 
            if(pb==nullptr)
                pb=headA;
            else pb=pb->next;//每轮pb只移动一次
        }
        return nullptr;//没有交点
    }
};
