/*
泰波那契序列 Tn 定义如下： 
T0 = 0, T1 = 1, T2 = 1, 且在 n >= 0 的条件下 Tn+3 = Tn + Tn+1 + Tn+2
给你整数 n，请返回第 n 个泰波那契数 Tn 的值。
示例 1：
输入：n = 4
输出：4
解释：
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
示例 2：
输入：n = 25
输出：1389537
提示：
0 <= n <= 37
答案保证是一个 32 位整数，即 answer <= 2^31 - 1。
*/


class Solution {
public:
    int tribonacci(int n) {
        int pre3=0,pre2=1,pre1=1;//递推的前三个数字
        int res=0;//当前数字
        if(n==0)
            return pre3;//dp[0]=0
        if(n==1)
            return pre2;//dp[1]=1
        if(n==2)
            return pre1;//dp[2]=1
        while(n>=3)//dp[3]-dp[n]
        {
            res=pre1+pre2+pre3;//dp[i]=dp[i-1]+dp[i-2]+dp[i-3]
            pre3=pre2;//dp[i-3]前移
            pre2=pre1;//dp[i-2]前移
            pre1=res;//dp[i-1]前移
            n--;
        }
        return res;
    }
};
