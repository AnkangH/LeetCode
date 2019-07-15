/*
给定一个字符串s，找到其中最长的回文子序列。可以假设s的最大长度为1000。
示例 1:
输入:
"bbbab"
输出:
4
一个可能的最长回文子序列为 "bbbb"。
示例 2:
输入:
"cbbd"
输出:
2
一个可能的最长回文子序列为 "bb"。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));//s[i,j]中的回文序列最大长度
        int res=0;
        for(int i=n-1;i>=0;i--)//i降序
            for(int j=i;j<n;j++)//j升序 且保证i<=j 因为求dp[i][j]需要先求dp[i+1][j-1]
            {
                if(i==j)
                    dp[i][j]=1;//一个字母 是回文
                else
                {
                    if(j-i>=2)//不相邻
                    {
                        if(s[i]==s[j])
                            dp[i][j]=dp[i+1][j-1]+2;//中间的回文最大长度+2
                        else
                            dp[i][j]=max(dp[i+1][j],dp[i][j-1]);//中间的最大回文长度
                    }
                    else//相邻
                    {
                        if(s[i]==s[j])
                            dp[i][j]=2;//相同则构成回文 长度为2
                        else
                            dp[i][j]=1;//不同则不构成回文 长度为1
                    }
                        
                }
                res=max(res,dp[i][j]);//保存最大回文长度
            }
        return res;
    }
};
