/*
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
说明：
拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：
输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
*/


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<bool> dp(n,false);//dp[i]代表 s(0,i)能否被词典拆分
        unordered_map<string,bool> m;//词典哈希表
        for(auto p:wordDict)
            m[p]=true;//构建词典哈希表
        for(int i=0;i<n;i++)
        {
            if(m.count(s.substr(0,i+1))!=0)
                dp[i]=true;//在词典中 能被词典表示
            else
            {
                for(int j=i-1;j>=0;j--)
                {
                    if(dp[j]&&m.count(s.substr(j+1,i-j))!=0)
                    {
                        dp[i]=true;//s(0,j)能被词典表示且s(j+1,i)在词典中 则s(0,i)能被词典表示
                        break;//找到后退出即可 减小遍历的次数
                    }
                }
            }
        }
        return dp[n-1];
    }
};
