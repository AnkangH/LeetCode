/*
给定一位研究者论文被引用次数的数组（被引用次数是非负整数）。编写一个方法，计算出研究者的 h 指数。
h 指数的定义: “h 代表“高引用次数”（high citations），一名科研人员的 h 指数是指他（她）的 （N 篇论文中）至多有 h 篇论文分别被引用了至少 h 次。
（其余的 N - h 篇论文每篇被引用次数不多于 h 次。）”
示例:
输入: citations = [3,0,6,1,5]
输出: 3 
解释: 给定数组表示研究者总共有 5 篇论文，每篇论文相应的被引用了 3, 0, 6, 1, 5 次。
     由于研究者有 3 篇论文每篇至少被引用了 3 次，其余两篇论文每篇被引用不多于 3 次，所以她的 h 指数是 3。
说明: 如果 h 有多种可能的值，h 指数是其中最大的那个。
*/


class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l=0,r=citations.size();//0一定符合 最多有n篇可能符合
        while(l<=r)
        {
            int mid=(r-l)/2+l;//当前被引次数
            int h=0;//记录数组中被引次数>=mid的数目 即mid是否符合要求
            for(auto p:citations)
                if(p>=mid)//至少为mid
                    h++;//计数增加
            if(h<mid)//说明mid太大 满足的数目少
                r=mid-1;//减小mid
            else//满足条件 找最大的数目
                l=mid+1;//增大mid
        }
        return r;//注意最后一次不满足 r会左移 此时r为正确答案
    }
};
