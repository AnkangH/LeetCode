/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.
Example:
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:
X X X X
X X X X
X X X X
X O X X
Explanation:
Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. 
Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected 
if they are adjacent cells connected horizontally or vertically.
解析：给定一个二维矩阵，将所有被X包围的O替换为X。当O在边界上时，不能替换。
DFS解法。注意不能使用回溯法，考虑 
       X
    X  O1  X
    X  O2  O3， 从O1检索时，O1->O2->O3为一条路径，因此发现O3在边界上时，可以回溯将O1和O2再复用成'O'，但是如果从O2出发，在判断O1的子程序中，
    周围均为X，因此不是边界条件，而从O2->O3发现了O3是边界上的O，因此要把O2和O1都复用回O，但此时O1的递归程序已经退出，无法确定O1的下标。如果
    使用静态变量vector保存修改过的字符索引，那么又会与成功修改的发生冲突，使用返回值也只能返回一个索引，并且如果使用返回值，那么是否发现了边界
    上的O又不能表达。
解决办法是，将O分类，所有与边界上的O相连（4连通）的O都是不可修改的，而所有不与边界相连的O都是需要修改的。因此dfs程序设为将所有与O相连的O改为其他字符，
如*。第一次先对矩阵的边界上所有点进行dfs搜索，将所有与边界上的O相连的O改为O和X之外的某个字符，再对矩阵所有点进行dfs，将内部与O相连的O全部改为X，最后
将矩阵中的所有*复原为O即可。
*/
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty())
            return;
        int m=board.size();
        int n=board[0].size();
        //边界上的所有'O'暂时修改为'*'
        for(int i=0;i<n;i++)
        {
            dfs(board,0,i,'*');//第一行
            dfs(board,m-1,i,'*');//最后一行
        }
        for(int i=0;i<m;i++)
        {
            dfs(board,i,0,'*');//第一列
            dfs(board,i,n-1,'*');//最后一列
        }
        //内部的'O'改为'X'
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                dfs(board,i,j,'X');
        //暂时修改的'*'复原为'O'
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(board[i][j]=='*')
                    board[i][j]='O';
    }
    void dfs(vector<vector<char>>& board,int i,int j,char c)
    {
        int m=board.size();
        int n=board[0].size();
        if(i<0||i>=m||j<0||j>=n||board[i][j]!='O')
            return;//跳过本次程序中的下列语句
        board[i][j]=c;
        dfs(board,i+1,j,c);
        dfs(board,i-1,j,c);
        dfs(board,i,j+1,c);
        dfs(board,i,j-1,c);
    }
};
