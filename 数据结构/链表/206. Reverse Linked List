/*
反转一个单链表。
示例:
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
*/


//方法一： 头插法 如上解析所示
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre=nullptr;//前节点
        ListNode* cur=head;//当前节点
        while(cur!=nullptr)//cur遍历原链表
        {
            ListNode* nxt=cur->next;//保存下个节点 防止断链后无法遍历原链表
            cur->next=pre;//反转
            pre=cur;//前节点前移
            cur=nxt;//当前节点后移
        }
        return pre;//最后一次反转后 pre为原链表最后一个非nullptr节点
    }
};


//方法二 使用stack的LIFO特性 原链表依次入栈 到链表尾后 出栈重建链表
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
            return head;//空链表判断
        ListNode* p=head;//不对输入做修改
        stack<ListNode*> st;//辅助栈
        while(p!=NULL)
        {
            st.push(p);//原链表入栈
            p=p->next;
        }
        ListNode* res=new ListNode(1);//声明链表节点时一定要用ListNode(int)，不能赋NULL，否则没有空间，不能访问res->next
        ListNode* pp=res;//res保存结果的链表头，用res副本pp重建链表，最后输出res->next即可。
        while(!st.empty())
        {
            ListNode* temp= new ListNode(st.top()->val);//新节点
            pp->next=temp;//做为新链表的后节点
            pp=pp->next;//当前节点向后移动
            st.pop();//出栈
        }
        pp->next=NULL;//链表尾添加NULL
        return res->next;//这样重建后，因为声明新链表的时候，首节点必须有值，所以最后链表为1->5->4->3->2->1->NULL,首节点为自定义的值
                         //所以要输出首节点的下一个节点。
    }
};
