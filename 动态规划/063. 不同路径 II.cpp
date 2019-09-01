/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
网格中的障碍物和空位置分别用 1 和 0 来表示。
说明：m 和 n 的值均不超过 100。
示例 1:
输入:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
输出: 2
解释:
3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右
*/


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(grid.empty()||grid[0][0]==1)//矩阵为空 或者起点为障碍物 路径数为0
            return 0;
        vector<vector<int>> dp(m,vector<int>(n,0));//从grid[0][0]到grid[i][j]的最大路径数
        dp[0][0]=1;
        for(int i=1;i<n;i++)//第一行 只能由grid[0][0]到达 路径最大数为1
        {
            if(grid[0][i]==0)
                dp[0][i]=1;
            else
                break;
        }
        for(int i=1;i<m;i++)//第一列 只能由grid[0][0]到达 路径最大数为1
        {
            if(grid[i][0]==0)
                dp[i][0]=1;
            else
                break;
        }
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
            {
                if(grid[i][j]==1)
                    dp[i][j]=0;
                else
                {
                    if(INT_MAX-dp[i][j-1]<dp[i-1][j])
                        dp[i][j]=0;//自底向上的递推 其中某些dp[i][j]不是dp[m-1][n-1]需要的 根据int范围判断
                    else
                        dp[i][j]=dp[i][j-1]+dp[i-1][j];
                }
            }
        return dp[m-1][n-1];//从grid[0][0]到grid[m-1][n-1]的最大路径数
    }
};
