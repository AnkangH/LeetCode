/*
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
示例 1:
输入: coins = [1, 2, 5], amount = 11
输出: 3 
解释: 11 = 5 + 5 + 1
示例 2:
输入: coins = [2], amount = 3
输出: -1
说明:
你可以认为每种硬币的数量是无限的。
*/


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);//零钱金额找零的最小数目
        for(auto p:coins)
        {
            if(p<=amount)//不超过总金额
                dp[p]=1;//零钱面额只需一张
        }
        dp[0]=0;//总金额为0时一张都不找
        for(int i=0;i<=amount;i++)
        {
            if(dp[i]==1)
                continue;//零钱面额的找零钱是最少的 只需一张
            int n=coins.size();
            for(auto p:coins)
                if(p<i&&dp[i-p]!=-1)//最后一张找面值为p的可以
                {
                    if(dp[i]==-1)
                        dp[i]=dp[i-p]+1;//第一次 赋值
                    else
                        dp[i]=min(dp[i],dp[i-p]+1);//其余取最小数量
                }
        }
        return dp[amount];
    }
};
