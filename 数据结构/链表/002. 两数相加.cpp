/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int flag=0;
        int cof=1;
        ListNode* resHead=new ListNode(1);//新链表头
        ListNode* res=resHead;//新链表构造头
        int cur=0;
        while(l1!=nullptr||l2!=nullptr)//有一链表不到链表尾
        {
            if(l1==nullptr)//链表1已遍历完
            {
                cur=flag+l2->val;
                l2=l2->next;
            }
            else if(l2==nullptr)//链表2已遍历完
            {
                cur=flag+l1->val;
                l1=l1->next;
            }
            else//链表1和链表2都未遍历完
            {
                cur=flag+l1->val+l2->val;
                l1=l1->next;
                l2=l2->next;
            }
            res->next=new ListNode(cur%10);//当前值
            flag=cur/10;//进位
            res=res->next;//移动新链表的构造头
        }
        if(flag!=0)
            res->next=new ListNode(1);//最后仍有进位 增加一个节点
        return resHead->next;
    }
};


//2021.4.4复习
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 链表头和遍历用的链表头
        ListNode* result = new ListNode();
        ListNode* cur_head = result;
        int flag = 0;
        // 遍历直到两个链表都到链表尾
        while(l1 || l2){
            
            if(l1) {
                flag+=l1->val;
                l1=l1->next;
            }
            if(l2) {
                flag += l2->val;
                l2=l2->next;
            }
            
            // 更新当前节点值
            cur_head->val = flag % 10;
            flag /= 10;
            
            //仍需计算下一个节点值
            if(l1 || l2 || flag){
                cur_head->next = new ListNode(flag);
                cur_head = cur_head->next;
            }
        }
        return result;
    }
};

/*
    1.链表用new的方式返回指针 否则空链表为nullptr无法赋值
    2.链表头和遍历头 因为使用指针所以只能修改指针的属性而无法修改指针本身 cur_head = nullptr并不会生效
*/
