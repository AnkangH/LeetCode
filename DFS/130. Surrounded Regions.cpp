/*
给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
示例:
X X X X
X O O X
X X O X
X O X X
运行你的函数后，矩阵变为：
X X X X
X X X X
X X X X
X O X X
解释:
被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。
如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/surrounded-regions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//
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


//2019-07-07更新
class Solution {
public:
    int m,n;
    void solve(vector<vector<char>>& board) {
        if(board.empty())
            return;
        m=board.size();
        n=board[0].size();
        for(int i=0;i<n;i++)//遍历列
        {
            dfs(board,0,i,'*');//第0行
            dfs(board,m-1,i,'*');//最后一行
        }
        for(int i=0;i<m;i++)
        {
            dfs(board,i,0,'*');//第一列
            dfs(board,i,n-1,'*');//最后一列
        }
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                if(board[i][j]=='O')
                    dfs(board,i,j,'X');//除边界外的部分
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(board[i][j]=='*')
                    board[i][j]='O';//将所有的'*'复原为'O'
            
    }
    void dfs(vector<vector<char>>& board,int r,int c,char ch)//true 可以修改 false不可修改
    {
        if(r<0||r>=m||c<0||c>=n||board[r][c]!='O')//被不是O的包围
            return;//退出
        board[r][c]=ch;//修改当前O->ch
        dfs(board,r+1,c,ch);//右
        dfs(board,r-1,c,ch);//左
        dfs(board,r,c+1,ch);//下
        dfs(board,r,c-1,ch);//上
    }
};
