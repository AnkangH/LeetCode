/*
给定一个无序的整数数组，找到其中最长上升子序列的长度。
示例:
输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
说明:
可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
*/


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int n=nums.size();
        vector<int> dp(n,1);//nums(0,i)中的最长递增子序列
        int res=dp[0];//最大值
        for(int i=1;i<n;i++)//遍历数组
        {
            for(int j=i-1;j>=0;j--)//前面所有元素中 递增序列最长的那个
                if(nums[i]>nums[j])//当前值比前面值大 递增序列可以增长
                    dp[i]=max(dp[i],dp[j]+1);//保留最大递增序列
            res=max(res,dp[i]);//保留dp[i]最大值
        }
        return res;
    }
};
