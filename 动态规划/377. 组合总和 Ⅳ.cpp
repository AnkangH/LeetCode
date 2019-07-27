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


//方法1 自下向上递推
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


//方法2 自上向下递推 使用备忘录
class Solution {
public:
    unordered_map<int,int>m;//备忘录 若dp[i]已存在 直接查表 避免递归的重复求取相同值
    int combinationSum4(vector<int>& nums, int target) {
        return dfs(nums,target);
    }
    int dfs(vector<int>&nums,int target)
    {
        if(target==0)
            return 1;//dp[0]=1;
        int res=0;//当前target的组合数
        for(auto p:nums)//遍历数组
            if(p<=target)//dp[target-p]合法
            {
                if(m.count(target-p)==0)//dp[i]未求取
                {
                    int cur=dfs(nums,target-p);//求dp[i]
                    m[target-p]=cur;//放入备忘录中
                    res+=cur;//dp[target]=sum(dp(target-p));
                }
                else
                    res+=m[target-p];//dp[i]已求取 查表
            }
        return res;
    }
};
