/*
现有一种使用字母的全新语言，这门语言的字母顺序与英语顺序不同。
假设，您并不知道其中字母之间的先后顺序。但是，会收到词典中获得一个 不为空的 单词列表。因为是从词典中获得的，
所以该单词列表内的单词已经 按这门新语言的字母顺序进行了排序。
您需要根据这个输入的列表，还原出此语言中已知的字母顺序。
示例 1：
输入:
[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]
输出: "wertf"
示例 3：
输入:
[
  "z",
  "x",
  "z"
] 
输出: "" 
解释: 此顺序是非法的，因此返回 ""。
注意：
你可以默认输入的全部都是小写字母
假如，a 的字母排列顺序优先于 b，那么在给定的词典当中 a 定先出现在 b 前面
若给定的顺序是不合法的，则返回空字符串即可
若存在多种可能的合法字母顺序，请返回其中任意一种顺序即可
*/


class Solution {
public:
    string alienOrder(vector<string>& words) 
    {
      vector<vector<bool>> ad(26,vector<bool>(26,false));//邻接表 若a在b前 有ad[a][b]=true
      vector<int> inDec(26,INT_MAX);//每个出现字母的入度
      vector<bool> known(26,false);//出现过的字母
      int n=words.size();//单词数目
      for(int i=0;i<n-1;i++)//12 23...n-2,n-1
      {
        int sizea=words[i].size();
        int sizeb=words[i+1].size();
        int size=min(sizea,sizeb);
        for(int j=0;j<sizea;j++)
          known[words[i][j]-'a']=true;//保存当前单词中出现的字母
        for(int j=0;j<size;j++)
          if(words[i][j]!=words[i+1][j])//相邻单词第一个不同字母 
          {
            ad[words[i][j]-'a'][words[i+1][j]-'a']=true;//构建邻接关系
            break;//退出
          }
      }
      for(auto p:words[n-1])
        known[p-'a']=true;//最后一个单词出现的字母 记录
      int cnt=0;//出现过的字母数目
      for(int i=0;i<26;i++)
        if(known[i])
        {
          inDec[i]=0;//出现过的字母 入度初始化为0
          cnt++;//出现过的字母
        }
      for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
        {
          if(j==i)
            continue;//跳过a->a
          if(ad[i][j])
            inDec[j]++;//a->b 则b的入度+1
        }
      queue<int> q;//拓扑排序辅助队列
      string res;
      for(int i=0;i<26;i++)
        if(inDec[i]==0)
          q.push(i);//入度为0的先入队列
      while(!q.empty())
      {
        int cur=q.front();//当前字母
        q.pop();
        res+=cur+'a';//放入拓扑排序中
        for(int i=0;i<26;i++)
          if(ad[cur][i])//当前字母的邻接表每个字母
          {
            inDec[i]--;//其入度-1
            if(inDec[i]==0)
              q.push(i);//若入度为0 则入队列
          }
      }
      if(res.size()==cnt)
        return res;//出现所有字母有拓扑排序
      else
        return "";//无拓扑排序
    }
};
  
