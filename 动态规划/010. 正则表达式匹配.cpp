/*
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
'.' 匹配任意单个字符  '*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
说明:
s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。

s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。

s = "aa"
p = "a*"
输出: true
解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。

s = "ab"
p = ".*"
输出: true
解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。

s = "aab"
p = "c*a*b"
输出: true
解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。

s = "mississippi"
p = "mis*is*p*."
输出: false
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/regular-expression-matching
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));//dp[i][j] s(i)和p(j)是否匹配 i,j代表前几个字符
        dp[0][0]=true;//初始值 空字符串能匹配
        for(int i=2;i<=n;i++)
            if(p[i-1]=='*')
                dp[0][i]=dp[0][i-2]||dp[0][i-1];//'*和前面一个字符都消掉' 或者只消去* 
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==p[j-1]||p[j-1]=='.')//当前字符相同
                    dp[i][j]=dp[i-1][j-1];//与上个子串的匹配关系相同
                else if(j>=2&&p[j-1]=='*')//p子串至少有两个字符 且最后一个为'*' 因为只有一个'*'无效
                {
                    if(s[i-1]==p[j-2]||p[j-2]=='.')//p的*之前的字母能匹配s当前字母
                        dp[i][j]=dp[i][j-1]||dp[i][j-2]||dp[i-1][j]||dp[i-1][j-1];//dp[i][j-1] p删除*  dp[i][j-2] p删除*和前面的一个字母
                        //dp[i-1][j-1] 代表p重复一次*前面的字母  dp[i-1][j] p重复两次*前面的字母
                    else//p *之前的字母不能匹配s当前字母
                        dp[i][j]=dp[i][j-2];//p删除*及之前一个字母 之后是否能匹配
                }
            }
        return dp[m][n];
    }
};
