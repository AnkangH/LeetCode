/*
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
给定一个整数 n，返回 n 皇后不同的解决方案的数量。
示例:
输入: 4
输出: 2
解释: 4 皇后问题存在如下两个不同的解法。
[
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-queens-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    int res;
    int totalNQueens(int n) {
        vector<int> temp;
        vector<bool> known(n,false);
        for(int i=0;i<n;i++)
            dfs(temp,known,n,i);//第一行i列放置第一个皇后 对之后的列表dfs
        return res;
    }
    void dfs(vector<int>&temp,vector<bool>& known,int n,int index)//进入dfs的列标都是合法的
    {
        temp.push_back(index);//记录当前皇后的行标列标(i,temp[i])
        known[index]=true;//标记当前列已有
        int size=temp.size();//判断是否是一种放置方法
        if(size==n)
            res++;//方法数目+1
        for(int i=0;i<n;i++)
        {
            if(known[i])
                continue;//当前i列已有皇后 跳过 保证列标不同
            bool flag=true;
            int size=temp.size();
            for(int j=size-1;j>=0;j--)//(size,i) (j,temp[j])
            {
                if(abs(size-j)==abs(i-temp[j]))//保证不在同一斜线上
                    flag=false;
            }
            if(flag)
                dfs(temp,known,n,i);//使用使用push_back的方法，行标必不同
        }
        temp.pop_back();//当前方法回溯
        known[index]=false;//当前列标已读回溯
    }
};
