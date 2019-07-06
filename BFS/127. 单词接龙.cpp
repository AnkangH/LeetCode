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
解释: endWord "cog" 不在字典中，所以无法进行转换。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-ladder
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


//每个单词的邻接表采用vector保存 
class Solution {
public:
int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
	int size = wordList.size();
    int wordSize=beginWord.size();
	unordered_map<string,bool> word;//记录词典
    unordered_map<string,vector<string>> ladder;//记录邻接表
	unordered_map<string, bool> dup;//记录是否访问
	for(int i=0;i<size;i++)
        word[wordList[i]]=true;
    if(word.count(endWord)==0)
        return 0;
	//构建有向图
    for(int i=0;i<size;i++)
    {
        vector<string> temp;
        for(int j=0;j<wordSize;j++)//每一位更换字母后是否在词典中
        {  
            string str=wordList[i];
            char c=str[j];
            for(int i=0;i<26;i++)
            {
                if(i+'a'!=c)
                {
                    str[j]=i+'a';
                    if(word.count(str))
                        temp.push_back(str);//更换字符后的单词放入邻接表中
                } 
            }
        }
        ladder[wordList[i]]=temp;
    }
    //添加初值的邻接表
    vector<string> beginLadder;
    for(int i=0;i<wordSize;i++)
    {
        string str=beginWord;
        char c=str[i];
        for(int j=0;j<26;j++)
        {
            if(j+'a'!=c)
            {
                str[i]=j+'a';
                if(word.count(str)!=0)
                    beginLadder.push_back(str);
            }
        }
    }
    ladder[beginWord]=beginLadder;
    //层序遍历
    queue<string> auxQue;
    auxQue.push(beginWord);
    dup[beginWord]=true;
    int path=0;
	while (!auxQue.empty())
	{
		int size = auxQue.size();//处理每一层
		path++;//层序
		for (int i = 0; i < size; i++)
		{
			string cur = auxQue.front();
			auxQue.pop();
			auto lad = ladder.find(cur)->second;//当前节点的邻接表
			int ladSize = lad.size();
			for (int j = 0; j < ladSize; j++)
				if (dup.count(lad[j]) == 0)
				{
					auxQue.push(lad[j]);
					dup[lad[j]] = true;
				}
			if (cur == endWord)
				return path;
		}
	}
	return 0;
}
};


//2019-07-06更新  每个单词的邻接表使用哈希表保存
class Solution {
public:
    unordered_map<string,bool> dict;//保存字典的哈希表
    unordered_map<string,unordered_map<string,bool>> ladder;//每个单词的邻接表
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for(auto p:wordList)
            dict[p]=true;//构建字典中每个单词的哈希表
        if(dict.count(endWord)==0)
            return 0;//终点不在字典中 返回0
        for(auto p:wordList)
            ladder[p]=generateTree(p);//生成每个单词的邻接表
        ladder[beginWord]=generateTree(beginWord);//生成初始单词的邻接表
        queue<string> q;//BFS辅助队列
        q.push(beginWord);//初始单词入队列 作为起点
        unordered_map<string,bool> exist;//因为是无向图 所以记录当前遍历的单词 防止重复使用
        int res=1;//记录层数
        while(!q.empty())
        {
            int size=q.size();//当前层的节点数
            for(int i=0;i<size;i++)//遍历每个节点
            {
                string temp=q.front();//当前节点
                if(temp==endWord)
                    return res;//找到终点单词 返回当前层数
                q.pop();
                auto p=ladder.find(temp)->second;//获取当前单词的词梯
                for(auto pp:p)//遍历词梯的每个单词
                {
                    if(exist.count(pp.first)==0)//未访问
                    {
                        q.push(pp.first);//入队列
                        exist[pp.first]=true;//标记已访问
                    }
                }
            }
            res++;//层数更新
        }
        return 0;
    }
    unordered_map<string,bool> generateTree(string word)
    {
        unordered_map<string,bool> d;
        int size=word.size();//单词的字母个数
        for(int i=0;i<size;i++)//遍历单词的每个字母
            for(int j=0;j<26;j++)//对当前字母使用25个字母代替
            {
                if(j+'a'!=word[i])//相同单词不再使用
                {
                    string temp=word;//构造不同单词
                    temp[i]='a'+j;//修改对应字母
                    if(dict.count(temp)!=0)//当前单词在字典中
                        d[temp]=true;//放入当前单词的词梯
                }
            }
        return d;
    }
};
