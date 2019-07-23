/*
给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​
设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
示例:
输入: [1,2,3,0,2]
输出: 3 
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)
            return 0;
        int n=prices.size();
        vector<int> sell(n,0);//到第i天 最后一次操作是卖出 sell[0]=0;
        vector<int> buy(n,0);//到第i天 最后一次操作是买入   
        vector<int> cold(n,0);//到第i天 最后一次操作是冷却期 cold[0]=0;
        buy[0]=-prices[0];//买入之后利润为0-price
        for(int i=1;i<n;i++)
        {
            sell[i]=max(sell[i-1],buy[i-1]+prices[i]);//第i天不买不卖 vs 第i天卖出
            buy[i]=max(buy[i-1],cold[i-1]-prices[i]);//第i天不买不卖  vs 第i天买入（买入必须经过冷却期）
            cold[i]=max(buy[i-1],max(cold[i-1],sell[i-1]));//第i天冷却期 前一天可能为买入 卖出 或冷却
        }
        return sell[n-1];
    }
};
