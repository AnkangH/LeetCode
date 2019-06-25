/*
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally 
or vertically neighboring. The same letter cell may not be used more than once.
Example:
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/


//时间复杂度不佳 因为使用传值
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()||word.empty())
            return false;
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(board[i][j]==word[0])
                    if(dfs(board,word,i,j,0))
                        return true;
        return false;
    }
    bool dfs(vector<vector<char>>&board,string word,int i,int j,int k)
    { 
        int m=board.size();
        int n=board[0].size();
        int sizeStr=word.size();
        if(k==sizeStr)//word[size-1]如果也相符，那么k会+1=size
            return true;
        if(i<0||i>=m||j<0||j>=n||word[k]!=board[i][j])
            return false;      
        char temp=board[i][j];
        board[i][j]='*';
        k++;
        bool path=dfs(board,word,i+1,j,k)||dfs(board,word,i-1,j,k)
            ||dfs(board,word,i,j+1,k)||dfs(board,word,i,j-1,k);
        //每个字符有三种情况 1.到达word终点 true 2.超边界或不符 false 3.当前相符 搜索四个方向
        //当进入当前字符a的四个方向搜索时，为防止对a的重复利用，保存当前a的字符，
        //将a先设为‘*’，使得搜索‘a’不符合如果这条路径搜索到最终发现不符，
        //那么从‘a’到最终所有被修改的字符都应复原.
        if(!path)
        {
            board[i][j]=temp;//复原
            return false;
        }
        else
            return true;
    }
};


//2019-06-25 更新 所有复用变量使用全局变量 时间复杂度空间复杂度俱佳 36ms（<85%）  9.8m(<99%)
class Solution {
public:
    int m=0,n=0;//矩阵大小
    int size=0;//单词长度
    string word;//单词
    bool exist(vector<vector<char>>& board, string str) {
        size=str.size();//单词长度赋值
        m=board.size();//矩阵行数赋值
        n=board[0].size();//矩阵列数赋值
        word=str;//单词赋值
        for(int i=0;i<m;i++)//遍历行
            for(int j=0;j<n;j++)//遍历列
                if(board[i][j]==word[0])//当前元素与单词首字母相同
                    if(dfs(board,i,j,0))//判断当前元素为起始元素 是否有路径等于单词
                        return true;//有单词路径返回true
        return false;//没有单词路径返回false
    }
    bool dfs(vector<vector<char>>& board,int i,int j,int index)//i,j为矩阵索引；index为单词索引
    {
        if(i<0||i>=m||j<0||j>=n||board[i][j]!=word[index])
            return false;//索引不合法或者当前元素不等于单词当前字母
        if(index==size-1)
            return true;//路径上所有字母都与单词对应相同 找到路径
        char temp=board[i][j];//保存当前字母 以便恢复
        board[i][j]='*';//修改当前字母防止往回搜索重复使用
        bool nxt=false;//是否有路径
        nxt=dfs(board,i+1,j,index+1)||dfs(board,i-1,j,index+1)||
            dfs(board,i,j+1,index+1)||dfs(board,i,j-1,index+1);//上下左右四个方向搜索
        if(!nxt)//搜索到不合法
            board[i][j]=temp;//将所有不合法路径上已修改的字母恢复
        return nxt;//返回
    }
};
