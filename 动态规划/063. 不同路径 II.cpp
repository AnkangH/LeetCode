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
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-paths-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m=g.size();
        int n=g[0].size();
        vector<vector<long>> dp(m,vector<long>(n,0));
        if(g[0][0]==0)//起点不是障碍物
            dp[0][0]=1;
        else
            dp[0][0]=0;//起点是障碍物 到右下角路径数一定为0
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(i==0&&j==0)
                    continue;//跳过dp[0][0]
                if(g[i][j]==1)//障碍物
                {
                    dp[i][j]=0;//可达路径为0
                    continue;//跳过下面语句
                }
                long path1,path2;//上面的方格和左面的方格到本方格的路径数
                if(i==0)//第一行
                    path1=0;//上面的方格路径为0
                else
                    path1=dp[i-1][j];//否则为上面的方格路径数目
                if(j==0)//第一列
                    path2=0;//左面的方格数目为0
                else
                    path2=dp[i][j-1];//否则为左面的方格路径数目
                dp[i][j]=path1+path2;//当前方格的路径数目
            }
        return dp[m-1][n-1];
       
    }
};
