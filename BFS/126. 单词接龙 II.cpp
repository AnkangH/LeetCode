/*
给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord 的最短转换序列。转换需遵循如下规则：
每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:
如果不存在这样的转换序列，返回一个空列表。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:
输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]
输出:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]
示例 2:
输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
输出: []
解释: endWord "cog" 不在字典中，所以不存在符合要求的转换序列。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-ladder-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        //1.边界条件及构建词典的哈希表
        vector<vector<string>> res;//接龙的所有路径
        if(wordList.empty())
            return res;//词典空 返回空
        unordered_map<string,bool> dict;//哈希表 记录每个词典中出现的单词
        for(auto p:wordList)
            dict[p]=true;//构建词典的哈希表
        if(dict.count(endWord)==0)
            return res;//如果终点单词不在词典中 返回空
        //2.构建邻接表
        unordered_map<string,vector<string>> ad;//构建每个单词的邻接表
        int n=wordList[0].size();//每个单词的长度相同
        for(auto p:wordList)//每个单词
        {
            vector<string> adj;
            for(int i=0;i<n;i++)//单词的每个字母
                for(int j=0;j<26;j++)//使用'a'-'z'替换
                {
                    if('a'+j!=p[i])
                    {
                        string temp=p;
                        temp[i]='a'+j;
                        if(dict.count(temp)!=0&&temp!=beginWord)//在词典中且与起点单词不同
                            adj.push_back(temp);//放入当前单词的邻接表中
                    }
                }
            if(!adj.empty())
                ad[p]=adj;//当前单词的邻接表非空 放入哈希表中
        }
        if(dict.count(beginWord)==0)//如果字典中不包含起始单词 需要构建起始单词的邻接表
        {
            vector<string> adBeginWord;//起始单词的邻接表
            for(int i=0;i<n;i++)
                for(int j=0;j<26;j++)
                    if('a'+j!=beginWord[i])
                    {
                        string temp=beginWord;
                        temp[i]='a'+j;
                        if(dict.count(temp)!=0)
                            adBeginWord.push_back(temp);
                    }
            if(!adBeginWord.empty())
                ad[beginWord]=adBeginWord;
        }
        //3.bfs 层序遍历
        queue<string> q;//辅助队列
        q.push(beginWord);//起点单词入队列
        unordered_map<string,bool> known;//所有单词的已读标志
        unordered_map<string,vector<vector<string>>> paths;//记录以每个单词为结尾的路径 可能有多个路径指向当前单词
        paths[beginWord]={{beginWord}};//起始单词的路径为该单词
        while(!q.empty())//层序遍历 或称无权无向图的最短路径算法
        {
            vector<string> layer;//记录当前层的所有单词
            unordered_map<string,bool> knownLayer;//当前层所有单词的哈希表
            while(!q.empty())//保存当前层所有单词并清空队列
            {
                layer.push_back(q.front());//放入当前层
                knownLayer[q.front()]=true;//标记该单词在当前层
                q.pop();
            }//此时队列为空
            for(auto p:layer)//遍历当前层每个单词
            {
                if(known[p]==true)//重复节点 不再访问
                    continue;
                known[p]=true;//标记当前单词已访问
                if(ad.count(p)!=0)//邻接表非空
                {
                    auto nxt=ad.find(p)->second;//当前单词的邻接表
                    auto path=paths.find(p)->second;//到达当前单词的所有路径
                    for(auto p1:nxt)//遍历当前单词的下个单词
                    {
                        if(knownLayer.count(p1)!=0||known.count(p1)!=0)//在当前层 或者在上面的层 不再访问
                            continue;//如果c和b在当前层 a->c->b长于a->b  c的子节点在当前层 那么一定是直接访问其的路径短
                        for(auto p2:path)//当前单词的每个路径
                        {
                            auto p3=p2;//使用其副本构建新路径
                            p3.push_back(p1);//连接下个单词
                            paths[p1].push_back(p3);//放入下个单词的路径中
                        }
                        q.push(p1);//那么放入下一层
                    }
                }
            }
        }
        return paths.count(endWord)==0? res:paths.find(endWord)->second;//返回终点单词的路径
    }
};
