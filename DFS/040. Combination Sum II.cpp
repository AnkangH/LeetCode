/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates 
where the candidate numbers sums to target.
Each number in candidates may only be used once in the combination.
Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:
Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
解析：给定一个无序正整数数组，数字可能重复，任意选取（一个索引在一个组合中不能重复选取），使和等于目标值，求所有的组合方法。
首先根据上个题目可以判断，向后搜索可以防止互异元素中出现重复组合，其次如果数字有重复，那么应该先排序。并且重复数字不做为首个数字进行dfs。在选取中，第一次选取，无论选取多少个重复
数字，都可以，此时索引必连续。而之后的选取，因为与第一次的下标不同，所以索引必不连续，如果索引不连续，又当前数字与前一个数字相同，那么当前数字一定
不可选取，否则是重复组合。
例如  2 1 2 2 5。排序后，向后搜索的结果是 122 122 122 5。因为排序后1 2 2 2 5。搜索时的顺序是 arr[0] arr[1] arr[2]; arr[0] arr[1] arr[3]；
以及arr[0] arr[2] arr[3]。那么可以将i的值是否大于当前值+2做为判断依据，只要当前索引（dfs的第二个索引，即0之后的那个）与前一个索引不连续，那么判断其
是否与数组中前一个数字相同，若相同，则跳过。
*/
class Solution {
public:
    unordered_map<int,bool> dup;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(candidates.empty())
            return res;
        int size=candidates.size();
        sort(candidates.begin(),candidates.end());
        dfs(res,candidates,{},target,0);
        for(int i=1;i<size;i++)
        {
            if(candidates[i]!=candidates[i-1])
                dfs(res,candidates,{},target,i);
        }
        return res;
    }
    void dfs(vector<vector<int>>& res,vector<int>& nums,vector<int> temp,int target,int index)
    {
        temp.push_back(nums[index]);
        dup[index]=true;
        if(nums[index]==target)
        {
            res.push_back(temp);
            return ;
        }
        if(nums[index]>target)
            return ;
        int size=nums.size();
        for(int i=index+1;i<size;i++)
        {
            if(i-index>=2&&nums[i]==nums[i-1])
            //如1 2 2 2 5 首次访问2时 索引肯定是连续的 此时无论向后选多少个2都可以
            //但是当第二次选取时 如选索引1 3的2 只要索引3之前的元素与索引3相同 那么就不算新的组合
                continue;
            dfs(res,nums,temp,target-nums[index],i);
        }
    }
};


// 2019/06/19更新
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int size=candidates.size();
        vector<vector<int>> res;
        if(size==0)
            return res;//空数组 退出
        sort(candidates.begin(),candidates.end());//排序数组
        for(int i=0;i<size;i++)
        {
            if(i>0&&candidates[i]==candidates[i-1])//重复的首个数字不进行dfs
                continue;
            dfs(res,candidates,{},target,i);//以每个数字做为首数字 向后dfs
        }
        return res;
    }
    void dfs(vector<vector<int>>& res,vector<int>& nums,vector<int> temp,int target,int index)
    {
        if(nums[index]>target)//数组均为正数 当前和大于target 必不符 退出
            return;
        temp.push_back(nums[index]);//<=  入当前组合
        if(nums[index]==target)//= 将当前组合放入结果
        {
            res.push_back(temp);
            return;
        }
        int size=nums.size();
        for(int i=index+1;i<size;i++)//对其后的数字进行dfs
        {
            if(i>index+1&&nums[i]==nums[i-1])//重复数字只选第一次出现的 其后均不进行dfs 因为会重复
                continue;
            dfs(res,nums,temp,target-nums[index],i);
        }
    }
};
