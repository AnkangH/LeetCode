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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a=headA;
        ListNode* b=headB;
        while(a!=nullptr||b!=nullptr)//最后如果无交点 那么a和b一起停在nullptr
        {
            if(a==b)//交点 要求a->val==b->val &&a->next==b->next
            {
                cout<<a->val<<b->val<<endl;
                return a;
            }
            else  //先判断是否到达终点 若在后面判断 则无法退出while循环
            {
                //每轮a和b只能有一次移动 若不等于nullptr 向后 否则去遍历另外一个链表
                if(a==nullptr)
                    a=headB;//a到达a的终点，再去遍历b
                else
                    a=a->next;//a向后遍历
                if(b==nullptr)//
                    b=headA;//b到达b的终点 再去遍历a
                else
                    b=b->next;//b向后遍历
            }
        }
        return nullptr;//无交点
    }
};
