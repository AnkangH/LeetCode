/*
给定一个由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数。
示例:
nums = [1, 2, 3]
target = 4
所有可能的组合为：
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

请注意，顺序不同的序列被视作不同的组合。

因此输出为 7。
*/


class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,0);//组成和为i的组合数
        dp[0]=1;//使用一个数字组成dp[i]时
        for(int i=1;i<target+1;i++)
            for(auto p:nums)
                if(p<=i)
                {
                    if(dp[i]>INT_MAX-dp[i-p])//防止超int范围
                    {
                        dp[i]=0;//不要返回0 因为i可能不到target 但是有组合和为target
                        break;
                    }
                    dp[i]+=dp[i-p];//dp[i]=sum(dp[i-p]) p=nums[0]-nums[n-1],p<=i
                }
        return dp[target];
    }
};
