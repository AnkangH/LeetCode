/*
Given a set of distinct integers, nums, return all possible subsets (the power set).
Note: The solution set must not contain duplicate subsets.
Example:
Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> res;
        if(nums.empty())
            return res;//预处理
        int size=nums.size();
        res.push_back({});//先添加一个空集
        for(int i=0;i<size;i++)
        {
            vector<int> temp;
            dfs(res,nums,temp,i);//对于每个元素作为首个元素，dfs之后的元素
        }
        return res;
    }
    void dfs(vector<vector<int>>& res,vector<int>& nums,vector<int> temp,int index)
    {
        temp.push_back(nums[index]);//因此使用了temp的副本，所以不需要回溯
        res.push_back(temp);//保存当前长度的子集
        int size=nums.size();
        for(int i=index+1;i<size;i++)//向后dfs 当index超出数组边界后停止
            dfs(res,nums,temp,i);
    }
};
