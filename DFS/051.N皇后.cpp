/*
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
示例:
输入: 4
输出: [
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
解释: 4 皇后问题存在两个不同的解法。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-queens
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


//方法一 以行标作为参数来dfs 
class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        vector<bool>known(n,false);
        vector<int>temp(n);
        dfs(temp,known,0,n);//dfs时，列标0-n 所以一条语句即可。
        return res;
    }
    void dfs(vector<int>&temp,vector<bool>& known,int index,int n)
    {
        if(index==n)//有n个皇后已放置
        {
            vector<string> resTemp;
            for(int i=0;i<n;i++)
            {
                string s(n,'.');
                s[temp[i]]='Q';
                resTemp.push_back(s);
            }
            res.push_back(resTemp);
            return;
        }
        for(int i=0;i<n;i++)//index使用的副本 所以i=0执行完并退出后，i=1时index没有变
        {
            if(known[i])
                continue;
            bool nxt=true;
            for(int j=index-1;j>=0;j--)//temp[j]前面j行皇后所在的列
                if(abs(j-index)==abs(temp[j]-i))//对角线 (j,temp[j]) (index,i)行标之差与列标之差的绝对值相等
                {
                    nxt=false;
                    break;
                }
            if(nxt)
            {
                known[i]=true;
                temp[index]=i;
                dfs(temp,known,index+1,n);//dfs下一行
                known[i]=false;//不满足的组合  退出后清楚当前i的已读标志
            }
        }
        
    }
};


//方法二 以列标作为参数来dfs 先在第一行放置第一个皇后 再对剩余所有列进行dfs
class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        vector<int> temp;//记录每个可行方法的皇后放置位置(i,temp[i])
        vector<bool>known(n,false);//记录当前列是否已有皇后
        for(int i=0;i<n;i++)
            dfs(temp,known,i,n);//i为当前皇后的列标 行标由temp的大小决定 =temp.size()
        return res;
    }
    void dfs(vector<int>&temp,vector<bool>& known,int index,int n)
    {
        known[index]=true;//标记当前列已有皇后
        temp.push_back(index);//存入放置方法
        int size=temp.size();
        if(size==n)//得到一个可行的放置方法 存入结果中
        {
            vector<string> resTemp;
            for(int i=0;i<n;i++)
            {
                string s(n,'.');
                s[temp[i]]='Q';
                resTemp.push_back(s);
            }
            res.push_back(resTemp);//不要return 因为此时known[i]均不满足不会再dfs 保证函数尾删除本轮
        }
        for(int i=0;i<n;i++)//i代表列标 
        {
            if(known[i])
                continue;//保证不在同一列
            int size=temp.size();
            bool flag=true;
            for(int j=size-1;j>=0;j--)//当前皇后 (size,i), 上个皇后(j,temp[j])
            {
                if(abs(size-j)==abs(i-temp[j]))//在同一对角线 冲突
                {
                    flag=false;
                    break;//有一个冲突即不用再检查
                }
            }
            if(flag)//保证不在同一列且不在同一对角线
            {
                dfs(temp,known,i,n);//因为dfs之前先判断是否满足 所以只要进入dfs 则一定满足
            }
        }
        known[index]=false;//函数尾删除当前添加的元素
        temp.pop_back();//只有当上述判断均不满足时才会执行 即回溯
    }
};
