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


//2021.4.7
/*
    1.dp[i][i]的遍历可以放到一个遍历流程里 不需单独处理
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int n =s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start=0, end=0;
        // 判断s(i,j)需先判断s(i+1,j-1) 
        //所以 i是递减的 先知道s(i+1, )才能知道s(i)
        for(int i=n-1;i>=0;i--)
            for(int j=i;j<n;j++){
                //dp[i][i]单个字符为回文串
                if(j==i){
                    dp[i][j]=true;
                    if(j-i>end-start){
                        end=j;
                        start=i;
                    }
                }
                // i和j相邻 字符相同为回文串
                else if(j-i==1){
                    if(s[j]==s[i]){
                        dp[i][j]=true;
                        if(j-i>end-start){
                            end=j;
                            start=i;
                        }   
                    }
                }
                //否则 i (i+1 j-1) j 若中间的s(i+1,j-1)为回文串 且s[i]==s[j] 则s(i,j)为回文串
                else{
                    if(dp[i+1][j-1] && s[j]==s[i]){
                        dp[i][j]=true;
                        if(j-i>end-start){
                            end=j;
                            start=i;
                        }  
                    }
                }
            }
        return s.substr(start, end-start+1);
    }
};
