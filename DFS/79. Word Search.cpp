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
        //那么从‘a’到最终所有被修改的字符都应复原
        if(!path)
        {
            board[i][j]=temp;//复原
            return false;
        }
        else
            return true;
    }
};
