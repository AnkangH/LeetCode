/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water 
and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are 
all surrounded by water.
Example 1:
Input:
11110
11010
11000
00000
Output: 1
Example 2:
Input:
11000
11000
00100
00011
Output: 3
解析：给定一个二维数组，‘1’代表陆地，‘0’代表海洋。以4连通为连通条件，即若陆地的上下左右为陆地，视为同一个岛屿。且边界之外全部为‘0’海洋，即边界上的
陆地视为岛屿。求岛屿的数目。
DFS方法，搜索上下左右，若超边界或值不为‘1’，返回，若值为‘1’修改值为‘0’，并搜索其上下左右。
遍历数组，发现‘1’，岛屿数目+1，将所有4连通的陆地设为‘0’海洋，防止重复访问。
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
            return 0;
        int m=grid.size();
        int n=grid[0].size();
        int res=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]=='1')//从陆地开始向4连通方向搜索
                {
                    res++;//岛屿数目+1
                    dfs(grid,i,j);//所有四连通陆地全设为‘0’
                }
        return res;
    }
    void dfs(vector<vector<char>>& grid,int i,int j)
    {
        int m=grid.size();
        int n=grid[0].size();
        if(i<0||i>=m||j<0||j>=n||grid[i][j]!='1')
            return;//边界条件 返回
        grid[i][j]='0';//当前陆地设为海洋
        dfs(grid,i+1,j);//搜索四连通方向
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    }
};
