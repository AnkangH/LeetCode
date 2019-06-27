/*
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/generate-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        string temp;
        dfs(temp,'(',1,0,n);//先放入一个左括号 对剩余括号回溯
        return res;
    }
    void dfs(string& temp,char c,int l,int r,int n)
    {
        temp+=c;//当前括号放入暂时组合
        int size=temp.size();//判断字符串长度
        if(size==n*2)//满足一个n对括号 
            res.push_back(temp);//放入结果
        else if(l==n)//左括号已用完 只能放右括号
            dfs(temp,')',l,r+1,n);
        else if(l>r)//当前字符串中左括号数目大于右括号数组 可放左括号也可放右括号
        {
            dfs(temp,'(',l+1,r,n);//先放左扩号
            dfs(temp,')',l,r+1,n);//再放右括号
        }
        else//当前左括号=右括号 下一个只能放右括号
            dfs(temp,'(',l+1,r,n);
        temp.pop_back();//尾回溯 删除当前轮添加的括号
    }
};
