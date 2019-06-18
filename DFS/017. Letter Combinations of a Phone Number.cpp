/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
Example:
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
解析：给定一个手机键盘，输入一个数字字符串，给出所有可能的组合。即9宫格输入法，给出按键顺序，求所有可能的字母顺序。
DFS。一是不使用回溯，把添加当前字符后的字符串作为参数进行dfs，因为使用了新的变量添加字符，所以不需要回溯删除添加的字符。
*/

//方法一： DFS按字符串搜索
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

