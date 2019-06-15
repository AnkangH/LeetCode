//1.动态规划法
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty())
            return s;
        int size=s.size();
        vector<vector<bool>> dp(size,vector<bool>(size,false));
        for(int i=0;i<size;i++)
            dp[i][i]=true;
        int start=0,end=0;
        for(int i=size-1;i>=0;i--)//i递减
            for(int j=i+1;j<size;j++)//j从i之后递增 才能满足dp[i][j]的递推
            {
                if(i+1>j-1)//i和j相邻
                {
                    if(s[i]==s[j])//i和j相同
                    {
                        dp[i][j]=true;//是回文字符串
                        if(j-i>end-start)//记录最大长度
                        {
                            end=j;
                            start=i;
                        }
                    }
                    else
                        dp[i][j]=false;//否则为非回文字符串
                }
                else//s[i]和s[j]不相邻
                {
                    if(s[i]==s[j]&&dp[i+1][j-1])//s[i]和s[j]相同
                                                //且中间字符串为回文
                    {
                        dp[i][j]=true;
                        if(j-i>end-start)//记录最大长度
                        {
                            end=j;
                            start=i;
                        }
                    }
                    else
                        dp[i][j]=false;
                }
            }
        return s.substr(start,end-start+1);//返回最大长度的回文字符串
    }
};
