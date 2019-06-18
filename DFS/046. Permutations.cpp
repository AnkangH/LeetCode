/*
Given a collection of distinct integers, return all possible permutations.
Example:
Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
解析：DFS。以每一位数字为搜索起点，搜索所有未读的位。当长度等于要求的长度时，保存并退出该次函数体。以为没有使用引用&，所以不需要回溯。
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> res;
        if(nums.empty())
            return res;
        int sizeNums=nums.size();
        for(int i=0;i<sizeNums;i++)
        {
            vector<bool> known(sizeNums,false);//每次搜索标记是否已读
            vector<int> temp;//对不同的首位字母不可共用一个temp，除非每次结束时，temp清空
            dfs(res,nums,temp,known,i);//对每一个数字作为第一位开始dfs
        }
        return res;
    }
    void dfs(vector<vector<int>>& res,vector<int>&nums,vector<int> temp,vector<bool> known,int index)
    {
        int sizeNums=nums.size();
        temp.push_back(nums[index]);//保存当前数字
        known[index]=true;//标记当前数字已读
        if(temp.size()==nums.size())//到达要求的长度
        {
            res.push_back(temp);//保存结果
            return;//跳出本次函数体剩余语句
        }
        for(int i=0;i<sizeNums;i++)
            if(!known[i])//对所有未读的数字dfs
                dfs(res,nums,temp,known,i);
    }
};
