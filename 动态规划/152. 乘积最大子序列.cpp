/*
给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。
示例 1:
输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:
输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(2,vector<int>(n,0));
        dp[0][0]=nums[0];//最小乘积初始值
        dp[1][0]=nums[0];//最大乘积初始值
        int res=dp[1][0];
        for(int i=1;i<n;i++)
        {
            int a=dp[0][i-1]*nums[i];
            int b=dp[1][i-1]*nums[i];//a和b是连续乘积的最大和最小值
            dp[0][i]=min(nums[i],min(a,b));//若nums[i]为最大或最小 那么意味着从i开始再向后找子序列
            dp[1][i]=max(nums[i],max(a,b));
            res=max(res,dp[1][i]);//保留最大乘积
        }
        return res;
    }
};
