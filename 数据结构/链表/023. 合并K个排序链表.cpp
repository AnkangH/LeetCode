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
*/


//方法1 多个节点比较 取最小节点方法 
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


//方法2 堆排序方法
class Solution {
public:
    struct cmp
    {
        bool operator() (ListNode* a, ListNode* b)
        {
            return a->val>b->val;//堆的大顶小顶与比较函数相反 小顶堆使用>
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp> stack;//小顶堆
        for(auto p:lists)
        {
            if(p!=nullptr)//防止空链表 因为nullptr未定义比较函数
                stack.push(p);//放入链表头
        }
        ListNode* res=new ListNode(1);//新链表头
        ListNode* cur=res;//构建新链表的当前头
        while(!stack.empty())//堆中所有节点
        {
            auto temp=stack.top();//当前节点
            stack.pop();//出堆
            cur->next=temp;//放入新链表
            cur=cur->next;//新链表当前头后移
            if(temp->next!=nullptr)
                stack.push(temp->next);//因为放入的是next 所以需要检查next是否为nullptr
        }
        return res->next;//返回新链表头即可
    }
};
