/*
给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。
示例 1:
输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1。
示例 2:
输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
说明: 你可以假设 n 不小于 2 且不大于 58。
*/


//数学分析 优先拆3 如果剩余小于等于4则停止 否则继续拆3
class Solution {
public:
    int integerBreak(int n) {
        if(n==1)
            return 0;
        if(n==2)
            return 1;
        if(n==3)
            return 2;
        int res=1;//起始乘积
        while(n>4)//当前大于4
        {
            n-=3;//优先拆3
            res*=3;//乘积乘3
        }
        res*=n;//乘剩下的最后一个数字
        return res;//返回乘积
    }
};


//dp方法 同上。每隔3个可以再拆出一个3来 而拆3是使乘积最大的方法
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp={0,0,1,2,4,6,9};
        if(n<=6)
            return dp[n];
        for(int i=7;i<=n;i++)//dp[i]为数组中的第i-1个
            dp.push_back(3*dp[i-3]);//第7个之后 每个为前面第3个的3倍 因为每隔3个能拆出3来 而拆3可以使乘积最大
        return dp[n];//返回乘积
    }
};
