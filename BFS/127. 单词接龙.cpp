/*
给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：
每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:
如果不存在这样的转换序列，返回 0。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:
输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]
输出: 5
解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
     返回它的长度 5。
示例 2:
输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
输出: 0
*/


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,bool> dict;//词典哈希表
        for(auto p:wordList)
            dict[p]=true;//构建词典哈希表
        if(dict.count(endWord)==0)
            return 0;//词典中不包含endWord 因此无法转换
        unordered_map<string,vector<string>> ad;//邻接表
        for(auto p:wordList)//词典中每一个单词
        {
            int size=p.size();
            vector<string> str;
            for(int i=0;i<size;i++)//该单词每一位
            {
                for(int j=0;j<26;j++)//使用'a'-'z'替换该位字母
                {
                    if(j+'a'==p[i])
                        continue;//跳过相同单词
                    string temp=p;
                    temp[i]=j+'a';//使用副本修改该位字母
                    if(dict.count(temp)!=0)
                        str.push_back(temp);//该修改单词在词典中 放入当前单词的邻接表
                }
            }
            ad[p]=str;//构建当前单词的邻接表
        }
        if(dict.count(beginWord)==0)//起始单词不在词典中 构建起始单词的邻接表
        {
            int size=beginWord.size();
            vector<string> str;
            for(int i=0;i<size;i++)
            {
                for(int j=0;j<26;j++)
                {
                    if(j+'a'==beginWord[i])
                        continue;
                    string temp=beginWord;
                    temp[i]=j+'a';
                    if(dict.count(temp)!=0)
                        str.push_back(temp);
                }
            }
            if(!str.empty())
                ad[beginWord]=str;
        }
        queue<string> q;//辅助队列 层序遍历无权无向图
        unordered_map<string,bool> known;//记录当前节点是否已访问 防止重复访问
        q.push(beginWord);//起始单词放入队列
        known[beginWord]=true;//置为已读
        int layer=0;//记录层数
        while(!q.empty())
        {
            int size=q.size();//当前层的节点个数
            layer++;//下一层的层序
            for(int i=0;i<size;i++)//当前层的所有节点
            {
                auto cur=q.front();//当前节点
                q.pop();//出队列
                if(cur==endWord)
                    return layer;//找到最终单词 返回层序
                if(ad.count(cur)==0)
                    break;//当前单词没有邻接单词 不能构造 提前退出
                auto adi=ad.find(cur)->second;//当前单词的邻接表
                for(auto p:adi)//遍历当前单词的邻接表每个单词
                    if(!known[p])//还未访问
                    {
                        q.push(p);//放入队列
                        known[p]=true;//已读
                    }
            }
        }
        return 0;
    }
};
