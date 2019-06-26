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


//使用副本进行dfs  不需要回溯
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


//使用引用进行dfs  需要回溯
class Solution {
public:
    vector<vector<int>> res;//子集结果
    int size;//数组大小
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());//排序数组 以便求子集时跳过相同元素
        size=nums.size();//数组大小赋值
        vector<int> temp;//集合暂存变量
        res.push_back({});//空集是所有集合的子集
        for(int i=0;i<size;i++)//遍历数组
        {
            if(i>0&&nums[i]==nums[i-1])//排序后 跳过连续的重复数字
                continue;
            dfs(temp,nums,i);//不重复数字做为 子集的第一个元素 向后dfs
        }
        return res;
    }
    void dfs(vector<int>& temp,vector<int>& nums,int index)
    {
        temp.push_back(nums[index]);//放入当前数字
        res.push_back(temp);//子集数组从1开始 所有集合均为子集 放入结果
        for(int i=index+1;i<size;i++)//向后dfs
        {
            if(i>index+1&&nums[i]==nums[i-1])//索引连续时 重复数字可以选取 否则只能选第一个
                continue;//重复数字只选取第一个  如211 第二个1不再选择
            dfs(temp,nums,i);//向后dfs
        }
        temp.pop_back();//回溯 退出时删除本轮添加的元素
    }
};
