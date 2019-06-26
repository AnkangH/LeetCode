/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sums to target.
The same repeated number may be chosen from candidates unlimited number of times.
Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:
Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
解析：组合问题。
  给定一个正整数数组array和一个正整数target，数组中的数字可以重复使用，求所有和为该正整数target的数组元素组合。
  思路是DFS搜索，每次搜索时，从target中减去当前值，然后搜索整个数组。这样可以完成目标，但是会出现一个问题，因为求的是组合数目，因此会有
相同元素的不同排列，如[2,3,7]求和为7，如果对于每个当前数字，都从数组0开始到数组最后结束进行dfs，那么会出现223 232 322 7四种组合，而
实际上前三种组合是同一种，如果再利用哈希表的方法删除重复的元素，需要将vector<int>排序，转string再构造哈希表并查表，虽然能通过，但是
时间900+ms。
  解决方法是，对于每个当前选择的数字，向后进行dfs，这样对2进行dfs时，可以从237中选，而对3dfs时，只能从3和7中选，排除了重复
的组合。边界条件，当前值=目标值，和当前值大于目标值以及当前值小于目标值。
  方法一放上dfs+map删除重复元素的方法，是满足要求但很差的解决方案。方法二是对每个数字，只对其后的数字dfs的解决方法，时间70ms，是方法一的10分之一。
*/

//方法一
class Solution {
public:
    unordered_map<string,bool> dup;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> res;
        if(candidates.empty())
            return res;
        int size=candidates.size();
        for(int i=0;i<size;i++)
        {
            vector<int> temp;
            dfs(candidates,res,temp,target,i);
        }
        return res;
    }
    void dfs(vector<int>& nums,vector<vector<int>>& path,vector<int> temp,int target,int index)
    {    
        temp.push_back(nums[index]);
        if(nums[index]==target)
        {
            vector<int> sortArr=temp;//使用temp的副本
            sort(sortArr.begin(),sortArr.end());//对temp排序
            string str;
            for(auto p:sortArr)
                str+=(p+'0');//构造字符串
            if(dup.count(str)==0)//判断该组合是否出现过
            {
                path.push_back(temp);
                dup[str]=true;
            }
            return;
        }
        if(nums[index]>target)
            return;
        int sizeNums=nums.size();
        for(int i=0;i<sizeNums;i++)//每个数字都从数组开始到结尾进行dfs
            dfs(nums,path,temp,target-nums[index],i);
    }
};

//方法二
class Solution {
public:
    unordered_map<string,bool> dup;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> res;
        if(candidates.empty())
            return res;//预判断
        int size=candidates.size();
        for(int i=0;i<size;i++)//每个数字作为开始，dfs
        {
            vector<int> temp;//每个首数字dfs的暂存变量从空开始
            dfs(candidates,res,temp,target,i);
        }
        return res;
    }
    void dfs(vector<int>& nums,vector<vector<int>>& path,vector<int> temp,int target,int index)
    {   
        temp.push_back(nums[index]);//当前数字放入vector
        if(nums[index]==target)//和为target
        {
            path.push_back(temp);//保存组合
            return;//跳过下面语句
        }
        if(nums[index]>target)//当前和大于target
            return;//因为都是正数，所以和不可能再满足，结束dfs
        int size=nums.size();
        for(int i=index;i<size;i++)//对当前到数组结尾，和减去当前值，dfs
        {
            dfs(nums,path,temp,target-nums[index],i);
        }
    }
};

//方法三 2019/06/19更新
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(candidates.empty())
            return res;
        int size=candidates.size();
        for(int i=0;i<size;i++)
            dfs(res,candidates,{},target,i);//因为数字互异 所以对于nums[i] 使用其值及其后的值组合 就不会有重复
        return res;
    }
    void dfs(vector<vector<int>>& res,vector<int>& nums,vector<int> temp,int target,int index)
    {
        if(nums[index]>target)//正数 大于target便退出
            return;
        temp.push_back(nums[index]);//<=的情况 nums[index]都放入组合中
        if(nums[index]==target)//是一种组合
        {
            res.push_back(temp);//将该组合放入结果 退出
            return;
        }
        int size=nums.size();
        for(int i=index;i<size;i++)//nums[index]可以重复使用 i从index开始 到数组最后一个元素
            dfs(res,nums,temp,target-nums[index],i);//对nums[i]-nums[size-1]进行dfs
    }
};
