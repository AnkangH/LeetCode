/*
题目：
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence 
from beginWord to endWord, such that:
Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:
Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:
Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
解析：
BFS. 无向图(god->got,got->god)的单源(beginWord)无权(任意边等长度)最短路径(beginWord->endWord)问题。构造图时，若遍历字典，对每个单词判断字典剩余的单词中
有哪些是其邻接节点的话，时间复杂度O(N*N)，实际上在处理到33个case时就已经超时了。而应该对每个字典单词，通过修改每一位（'a'-'z'),判断修改
后的单词是否在字典中。时间复杂度O(N*26)，通过所有case.邻接表构造好后，按照层序遍历即可，每个节点只访问一次，当访问到最终节点时，最终节点的
层序即为最短路径。
*/
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
