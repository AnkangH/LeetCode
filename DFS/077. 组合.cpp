/*
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
示例:
输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combinations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        if(k>n)
            return res;//判断k合法性
        vector<int> temp;//暂存变量
        for(int i=1;i<=n;i++)
            dfs(temp,n,k,i);//从第i个元素向后dfs
        return res;
    }
    void dfs(vector<int>&temp,int n,int k,int index)
    {
        temp.push_back(index);//因为判断了index再dfs 所以只要进入dfs的index都合法
        int size=temp.size();
        if(size==k)
            res.push_back(temp);//满足条件 放入结果中
        for(int i=index+1;i<=n;i++)//对其后dfs 防止重复
            dfs(temp,n,k,i);
        temp.pop_back();//退出时回溯
    }
};
