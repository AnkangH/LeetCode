/*
给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。

示例1:
输入: pattern = "abba", str = "dog cat cat dog"
输出: true
示例 2:
输入:pattern = "abba", str = "dog cat cat fish"
输出: false
*/


class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char,string> m;//保存配对
        unordered_map<string,char> m2;//str中单词是否已有配对
        vector<string> s;//分割str为每个单词
        string temp;
        for(auto p:str)
        {
            if(p!=' ')
                temp+=p;
            else
            {
                s.push_back(temp);
                temp.clear();
            }
        }
        if(!temp.empty())
            s.push_back(temp);
        if(pattern.size()!=s.size())
            return false;//不对应 返回false
        int n=pattern.size();
        for(int i=0;i<n;i++)
        {
            if(m.count(pattern[i])==0&&m2.count(s[i])==0)//字母和单词都没有出现过 构建双向关系
            {
                m[pattern[i]]=s[i];
                m2[s[i]]=pattern[i];
            }
            else if(m.count(pattern[i])==1&&m2.count(s[i])==1)//都出现过
            {
                if(m[pattern[i]]!=s[i])
                    return false;//不匹配
            }
            else
                return false;//一个出现过一个没有出现过
        }
        return true;//匹配
    }
};
