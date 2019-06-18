/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
Note: The solution set must not contain duplicate subsets.
Example:
Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<vector<int>> res;
        if(nums.empty())
            return res;
        res.push_back({});//空集是所有集合的子集
        int size=nums.size();
        sort(nums.begin(),nums.end());
        dfs(res,nums,{},0);//先对第一个数字进行dfs 
        for(int i=1;i<size;i++)
            if(nums[i]!=nums[i-1])//之后的数字，只有第一次出现才dfs
                dfs(res,nums,{},i);
        return res;
    }
    void dfs(vector<vector<int>>& res,vector<int>& nums,vector<int> temp,int index)
    {
        temp.push_back(nums[index]);//保存当前元素
        res.push_back(temp);//保存当前子集
        int size=nums.size();
        for(int i=index+1;i<size;i++)//对之后的数字遍历
        {
            if(i>=index+2&&nums[i]==nums[i-1])//遍历的前后两个只要索引不连续且
                continue;//当前遍历的数字与其在数组中的前一个数字相同 那么当前遍历一定是重复组合 要剔除
            dfs(res,nums,temp,i);
        }
    }
};
