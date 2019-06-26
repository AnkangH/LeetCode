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

//使用副本进行合法dfs 不需要回溯 但是空间复杂度高
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

//使用引用进行dfs 需要回溯 时间复杂度空间复杂度俱佳
class Solution {
public:
    int size=0;//数组大小 使用全局变量减小空间复杂度
    vector<vector<int>> res;//保存 结果
    vector<vector<int>> subsets(vector<int>& nums) {
        size=nums.size();//数组大小赋值
        res.push_back({});//添加空集 空集是任何集合的子集
        vector<int> temp;//暂存变量
        for(int i=0;i<size;i++)//将数组当前元素作为第一个选取的元素 对其后的元素dfs 防止重复
            dfs(temp,nums,i);
        return res;
    }
    void dfs(vector<int>& temp,vector<int>& nums,int index)
    {
        temp.push_back(nums[index]);//合法index 将nums[index]放入结果
        res.push_back(temp);//因为集合个数从1开始 所以所有结果当合法
        for(int i=index+1;i<size;i++)//对其后的索引dfs
            dfs(temp,nums,i);
        temp.pop_back();//尾回溯 退出时删除当前添加的元素
    }
};
