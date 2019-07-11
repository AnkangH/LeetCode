/*
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
示例 1:
输入: [1,2,3,1]
输出: 4
解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
示例 2:
输入: [2,7,9,3,1]
输出: 12
解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int size=nums.size();
        vector<int> dp(size);//偷到第i个（第i个不一定要偷）的最大价值
        dp[0]=nums[0];
        if(size==1)//只有一个房间
            return dp[0];//只能偷这个房间
        dp[1]=max(nums[0],nums[1]);//两个房间的最大值
        if(size==2)//只有两个房间
            return dp[1];
        for(int i=2;i<size;i++)//遍历之后每一个房间
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);//+代表偷当前 否则不偷当前 取决于相邻的价值大小
        return dp[size-1];//返回偷完全部房间的最大价值
    }
};


//使用三个变量递推
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int size=nums.size();
        int pre2=nums[0];
        if(size==1)//只有一个房间
            return pre2;//只能偷这个房间
        int pre1=max(nums[0],nums[1]);//两个房间的最大值
        if(size==2)//只有两个房间
            return pre1;
        int res;
        for(int i=2;i<size;i++)//遍历之后每一个房间
        {
            res=max(pre2+nums[i],pre1);//+代表偷当前 否则不偷当前 取决于相邻的价值大小
            pre2=pre1;
            pre1=res;
        }
        return res;//返回偷完全部房间的最大价值
    }
};
