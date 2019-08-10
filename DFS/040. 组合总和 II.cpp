/*
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用一次。
说明：
所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
*/



class Solution {
public:
    vector<vector<int>> res;
    int n;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.empty())
            return res;//边界条件
        sort(candidates.begin(),candidates.end());//排序
        n=candidates.size();//数组大小
        vector<int> temp;//组合暂存
        for(int i=0;i<n;i++)
        {
            if(i>0&&candidates[i]==candidates[i-1])
                continue;//dfs的起始数字重复时 跳过重复组合
            dfs(candidates,temp,target,i);//以i作为第一个数字进行dfs
        }
        return res;
    }
    void dfs(vector<int>& nums,vector<int>& temp,int target,int idx)
    {
        temp.push_back(nums[idx]);//当前数字
        if(nums[idx]==target)
            res.push_back(temp);//满足和为target的一个组合放入组合总数
        for(int i=idx+1;i<n;i++)//其后的所有数字
        {
            if(i>=idx+2&&nums[i]==nums[i-1])
                continue;//非连续索引的重复数字为重复组合 跳过
            if(nums[i]<=target)
                dfs(nums,temp,target-nums[idx],i);//当前和小于target  继续dfs
        }
        temp.pop_back();//尾回溯
    }
};
