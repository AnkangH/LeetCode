/*
给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
例如，给定三角形：
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
说明：
如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/triangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();//行数
        int n=triangle[m-1].size();//最下面一行的列数
        vector<vector<int>> dp(m,vector<int>(n,0));//dp[i][j] 到达triangle[i][j]的最短路径和
        dp[0][0]=triangle[0][0];//初值
        if(m<2)
            return dp[0][0];//只有一行 返回triangle[0][0]
        int res=INT_MAX;//求最小路径 所以初值设为INT_MAX
        for(int i=1;i<m;i++)//遍历剩余行
        {
            int nCur=triangle[i].size();//当前行的列数
            for(int j=0;j<nCur;j++)//遍历当前行
            {
                if(j==nCur-1)//行尾
                   dp[i][j]=dp[i-1][j-1]+triangle[i][j];//只能由上一行的行尾到达
                else if(j==0)//行头
                    dp[i][j]=dp[i-1][0]+triangle[i][j];//只能由上一行的行头到达
                else//中间值
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+triangle[i][j];//取上一行中相邻两个的最短路径
                if(i==m-1)//到达最后一行
                    res=min(res,dp[i][j]);//取最后一行每个路径的最小值
            }
        }
        return res;
    }
};
