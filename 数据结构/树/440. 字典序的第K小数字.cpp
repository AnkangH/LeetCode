/*
给定整数 n 和 k，找到 1 到 n 中字典序第 k 小的数字。
注意：1 ≤ k ≤ n ≤ 109。
示例 :
输入:
n: 13   k: 2
输出:
10
解释:
字典序的排列是 [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]，所以第二小的数字是 10。
*/


class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur=1;
        k--;
        while(k>0)//执行k-1次
        {
            long l=cur,r=cur+1;//起点和终点
            int step=0;//
            while(l<=n)//十叉树中cur的所有子节点个数
            {
                step+=min(long(n+1),r)-l;// min保证参数同类型 子树中当前层的节点个数
                l*=10;//下一层起点
                r*=10;//下一层终点
            }
            if(step-k>0)//第k小元素在当前cur的子树中
            {
                k--;//cur在其子树中最小 所以整个树中第k小的数为cur的子树中第k-1小的数
                cur*=10;
            }
            else//第k小元素不在当前cur的子树中
            {
                k-=step;//cur的子树中所有节点均小于target 所以target是第k-step小元素
                cur++;//向cur的同层节点之后的节点搜索
            }
        }
        return cur;
    }
};
