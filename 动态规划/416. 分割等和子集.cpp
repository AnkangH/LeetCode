/*
给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
注意:
每个数组中的元素不会超过 100
数组的大小不会超过 200
示例 1:
输入: [1, 5, 11, 5]
输出: true
解释: 数组可以分割成 [1, 5, 5] 和 [11].
示例 2:
输入: [1, 2, 3, 5]
输出: false
解释: 数组不能分割成两个元素和相等的子集.\
*/


//二维dp 使用一维数组递推
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto p:nums)
            sum+=p;
        if(sum%2!=0)
            return false;
        sum/=2;//求一个子集 和为sum/2 即可
        int n=nums.size();
        vector<bool> dp(sum+1,false);//使用一维数组递推
        dp[0]=true;//递推初始值
        for(int i=1;i<=n;i++)
            for(int j=sum;j>=1;j--)
            {
                if(j-nums[i-1]>=0)
                    dp[j]=dp[j]||dp[j-nums[i-1]];//dp[i]的初始状态为上一次的状态 即dp[i-1][j]
            }
        return dp[sum];
    }
};


//回溯法 将特殊case 即包含很多1的给去掉 此时数组最大的数字超过sum/2 一定不存在两个和相等的子集
class Solution {
public:
    int n;
    bool res=false;
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto p:nums)
            sum+=p;
        if(sum%2!=0)
            return false;
        sum/=2;//求一个子集 和为sum/2 即可
        sort(nums.begin(),nums.end(),greater<int>());
        if(nums[0]>sum)
            return false;//如果最大的数字超过数组和的一半 那么肯定不存在两个和相等的子集
        n=nums.size();
        for(int i=0;i<n;i++)
            if(!res)
                dfs(nums,i,sum);//回溯法找一个子集 和为sum/2
        return res;
    }
    void dfs(vector<int>&nums,int idx,int target)
    {
        if(nums[idx]==target)
        {
            res=true;
            return;
        }
        if(!res)
        {
            for(int i=idx+1;i<n;i++)
                if(nums[i]<=target-nums[idx])
                    dfs(nums,i,target-nums[idx]);
        }
    }
};
