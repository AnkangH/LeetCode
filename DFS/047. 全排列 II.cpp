/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.
Example:
Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
解析：DFS搜索。对于所有可能的排列组合，产生方法都是DFS搜索，但是排除重复排列的方法不同。方法一：用一个map记录出现过的序列。因为不使用自定义的key值，所以map无法对vector<int>的key值检索，
需要将vector<int>转换为string，再进行检索。方法二：将所有可能的结果放入set中，利用set的互异性，再依次取出。

//方法一
class Solution {
public:
    unordered_map<string,bool> exist;
    int sizeNums;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty())
            return res;
        sizeNums=nums.size();
        for(int i=0;i<sizeNums;i++)
        {
            vector<bool> known=vector<bool>(sizeNums,false);
            vector<int>temp;
            dfs(res,nums,temp,known,i);
         }
        return res;
    }
    void dfs(vector<vector<int>>& res,vector<int>& nums,vector<int> temp,vector<bool>known,int index)
    {
        temp.push_back(nums[index]);//当前位
        known[index]=true;//标记已读
        if(temp.size()==nums.size())//长度到达边界
        {
            string str;
            for(auto p:temp)
                str+=(p+'0');//map无法对vector<int>的key值检索，这里用string代替
            if(exist.count(str)==0)//未出现
            {
                res.push_back(temp);//放入结果
                exist[str]=true;//标记已读
            }
            return;
        }
        for(int i=0;i<sizeNums;i++)
            if(!known[i])
                dfs(res,nums,temp,known,i);//对剩下未读字符进行dfs
    }
};

//方法
class Solution {
public:
    int sizeNums;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty())
            return res;
        int sizeNums=nums.size();
        unordered_map<int,bool> m1;
        unordered_map<int,bool>m2;//利用哈希表 将nums中的重复元素剔除
        for(int i=0;i<sizeNums;i++)
        {
            if(m2.count(nums[i])==0)
            {
                m2[nums[i]]=true;
                m1[i]=true;
            }
        }
        for(int i=0;i<sizeNums;i++)
        {
            if(m1.count(i)==1)
            {
                vector<bool> known=vector<bool>(sizeNums,false);
                vector<int>temp;
                dfs(res,nums,temp,known,i);
            }
         }
        set<vector<int>> auxSet;
        for(auto p:res)
            auxSet.emplace(p);
        res.clear();
        for(auto p:auxSet)
            res.push_back(p);
        return res;
    }
    void dfs(vector<vector<int>>& res,vector<int>& nums,vector<int> temp,vector<bool>known,int index)
    {
        int sizeNums=nums.size();
        temp.push_back(nums[index]);
        known[index]=true;
        if(temp.size()==nums.size())
        {
            res.push_back(temp);
            return;
        }
        for(int i=0;i<sizeNums;i++)
            if(!known[i])
                dfs(res,nums,temp,known,i);
    }
};
