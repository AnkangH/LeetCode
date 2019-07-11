/*
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
说明：
所有数字都是正整数。
解集不能包含重复的组合。 
示例 1:
输入: k = 3, n = 7
输出: [[1,2,4]]
示例 2:
输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    vector<vector<int>> res;//组合结果
    int kk;//k的全局变量 
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;//组合暂存
        kk=k;//k赋值
        for(int i=1;i<=9;i++)
            dfs(temp,i,n);//从1-9做为第一个数字，dfs后面的数字
        return res;
    }
    void dfs(vector<int>& temp,int val,int target)
    {
        temp.push_back(val);//当前数字放入结果
        int size=temp.size();//当前组合的数目
        if(target-val==0&&size==kk)//和为n且组合中数字的数目为k
            res.push_back(temp);//符合要求 放入最终结果
        for(int i=val+1;i<=9;i++)//不使用重复数字 对当前val之后到9的数字进行dfs
        {
            if(i<=target-val)//剪枝 对于不满足的情况 不进行dfs
                dfs(temp,i,target-val);//对i进行dfs 目标值减去当前值
        }
        temp.pop_back();//尾回溯
    }
};
