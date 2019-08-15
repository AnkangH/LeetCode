/*
给定一个整数矩阵，找出最长递增路径的长度。
对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外（即不允许环绕）。
示例 1:
输入: nums = 
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
] 
输出: 4 
解释: 最长递增路径为 [1, 2, 6, 9]。
*/


class Solution {
public:
    vector<vector<int>> memo;//dfs备忘录
    int m,n;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return 0;//数组空 返回空
        m=matrix.size();//行
        n=matrix[0].size();//列
        memo=vector<vector<int>>(m,vector<int>(n,0));//备忘录初始化为0
        int res=0;//最长递增路径的长度
        vector<vector<bool>> known(m,vector<bool>(n,false));//当前ij是否已访问
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                res=max(res,dfs(matrix,known,i,j));//以ij为地点求最长递增路径的长度
        return res;
    }
    int dfs(vector<vector<int>>& matrix,vector<vector<bool>>& known,int i,int j)
    {
        if(memo[i][j]!=0)
            return memo[i][j];//已知从i j出发的最长递增路径 直接返回
        int cur=0;//当前从i j出发最长递增路径的初始值 因为要取最大值 所以初始值设为0
        known[i][j]=true;//记录已访问
        if(i+1<m&&matrix[i][j]<matrix[i+1][j])
            cur=max(cur,dfs(matrix,known,i+1,j));//向下移动
        if(i-1>=0&&matrix[i][j]<matrix[i-1][j])
            cur=max(cur,dfs(matrix,known,i-1,j));//向上移动
        if(j+1<n&&matrix[i][j]<matrix[i][j+1])
            cur=max(cur,dfs(matrix,known,i,j+1));//向右移动
        if(j-1>=0&&matrix[i][j]<matrix[i][j-1])
            cur=max(cur,dfs(matrix,known,i,j-1));//向左移动
        memo[i][j]=cur+1;//保存到备忘录 
        known[i][j]=false;//退出时 置当前点未读
        return cur+1;//递增路径的最后一个点 上面四种移动都不会执行 因此cur=0 而要返回1
    }
};
