/*
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。
返回所有这些可能的句子。
说明：
分隔时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：
输入:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
输出:
[
  "cats and dog",
  "cat sand dog"
]
*/


class Solution {
public:
    vector<string> res;
    int n;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(s.empty()||wordDict.empty()||!isLegal(s,wordDict))
            return res;//有一为空 或s不能被拆分 返回空
        n=s.size();
        unordered_map<string,bool> dict;//单词哈希表
        for(auto p:wordDict)
            dict[p]=true;//构建单词哈希表
        vector<vector<bool>> dp(n,vector<bool>(n,false));//dp[i][j]代表s(i,j)是否在字典中
        for(int i=0;i<n;i++)
            for(int j=i;j<n;j++)
                if(dict.count(s.substr(i,j-i+1))!=0)
                    dp[i][j]=true;
        string temp;//拆分方法暂存
        for(int i=0;i<n;i++)
            if(dp[0][i])
                dfs(temp,dp,s,0,i);//s(0,i)在字典中 那么作为起点进行拆分
        return res;
    }
    void dfs(string& temp,vector<vector<bool>>& dp,string s,int i,int j)
    {
        string str=temp;//保存进入时的状态
        temp+=s.substr(i,j-i+1);//放入当前拆分的字符串
        if(j==n-1)
            res.push_back(temp);//到达字符串结尾 因此是一种可能的拆分方法
        temp+=" ";//间隔符
        j=j+1;//从下一个位置开始继续拆分
        for(int k=j;k<n;k++)
            if(dp[j][k])
                dfs(temp,dp,s,j,k);
        temp=str;//回溯 回到进入时的状态
    }
    bool isLegal(string s, vector<string>& wordDict) //判断s是否能被dict拆分
    {
        int n=s.size();
        vector<bool> dp(n,false);//s(0,i)能否被字典拆分
        unordered_map<string,bool> m;//字典哈希表
        for(auto p:wordDict)
            m[p]=true;//构造字典哈希表
        for(int i=0;i<n;i++)
        {
            if(m.count(s.substr(0,i+1))!=0)
                dp[i]=true;//s(0,i)在字典中 可以拆分
            else
            {
                for(int j=i-1;j>=0;j--)
                {
                    if(dp[j]&&m.count(s.substr(j+1,i-j))!=0)
                    {
                        dp[i]=true;//s(0,j)可以由字典拆分 且s(j+1,i)在字典中 则s(0,i)可以由字典拆分
                        break;
                    }
                }
            }
        }
        return dp[n-1];
    }
};
