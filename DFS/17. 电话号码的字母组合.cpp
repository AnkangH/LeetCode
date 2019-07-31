/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
示例:
输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
说明:
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
*/


//方法1  使用回溯法
class Solution {
public:
    vector<string> res;//组合结果
    vector<string> dict={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};//词典
    int n;//数字数目 即每个组合中字母的数目
    int size;//组合当前字母个数
    vector<string> letterCombinations(string digits) {
        n=digits.size();
        if(n==0)
            return res;//边界条件
        string temp;//组合暂存
        dfs(temp,digits,0);//从第一个数字开始dfs
        return res;
    }
    void dfs(string& temp,string digits,int i)
    {
        for(auto p:dict[digits[i]-'2'])//当前字符串的每个字母
        {
            temp.push_back(p);//放入组合暂存
            size=temp.size();
            if(size==n)//得到一个组合
            {
                res.push_back(temp);//放入结果
                temp.pop_back();//删除当前轮放入字母
            }
            if(i+1<n)
                dfs(temp,digits,i+1);//向后dfs
        }
        temp.pop_back();//删除上一轮字母 如af时 内层删除f，剩余a退出内层循环 此时删除a
    }
};


//方法2  使用副本dfs
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string temp;
        vector<string> res;
        if(digits.empty())
            return res;
        dfs(digits,temp,res,0);
        return res;
    }
    void dfs(string digits,string temp,vector<string>& res,int index)
    {
        if(temp.size()==digits.size())//到达长度
        {
            res.push_back(temp);//字符串放入结果
            return;//跳过剩余语句
        }
        string cur=dict[digits[index]-'2'];//以每一个字符串为dfs对象
        for(auto p:cur)
        {
            dfs(digits,temp+p,res,index+1);//每个字符串的每个字符进行dfs
        }
    }
private:
    vector<string> dict{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
};

