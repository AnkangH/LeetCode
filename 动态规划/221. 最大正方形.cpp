/*
在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。
示例:
输入: 
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
输出: 4
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximal-square
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        int m=matrix.size();//行数
        int n=matrix[0].size();//列数
        vector<vector<int>> dp(m,vector<int>(n,0));//dp数组 当前元素能构成的最大边长
        int res=0;//最大边长
        dp[0][0]=matrix[0][0]-'0';//dp起点
        res=max(res,dp[0][0]);//更新res
        for(int i=1;i<m;i++)
        {
            dp[i][0]=matrix[i][0]-'0';//第一列
            res=max(res,dp[i][0]);//更新res
        }
        for(int i=1;i<n;i++)
        {
            dp[0][i]=matrix[0][i]-'0';//第一行
            res=max(res,dp[0][i]);//更新res
        }
        for(int i=1;i<m;i++)//剩余行 [1,m-1]行
            for(int j=1;j<n;j++)//剩余列 [1,n-1]列
            {
                if(matrix[i][j]=='0')//当前为'0'
                    dp[i][j]=0;//dp为0
                else//当前为'1'
                {
                    int temp=dp[i-1][j-1];//当前可能的最大边长
                    int k=0;//记录最大边长
                    int a=i-1,b=j-1;//搜索起点dp[i][j-1]和dp[i-1][j]
                    for(k;k<temp;k++)
                    {
                        if(matrix[i][b]!='1'||matrix[a][j]!='1')//当前发现0 所以最大边长不可能再大了
                            break;//退出
                        a--;//当前列向上搜索
                        b--;//当前行向左搜索
                    }
                    dp[i][j]=k+1;//保留搜索到的最大边长
                }
                res=max(res,dp[i][j]);//记录当前最大边长
            }
        return res*res;//正方型面积=边长的平方
    }
};
