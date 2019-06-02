/*
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally 
(horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)
Example 1:
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:
[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50.

解析：给定一个二维矩阵，矩阵的值为0或1，求最大连通的1的数目，其中连通指4连通，即上下左右为1。
遍历矩阵，对每一个是1的的元素，dfs搜索上下左右。有两种情况，当前为0或超边界，返回0；当前为1，将当前设为0，防止其他的搜索对当前重复计数后，
对上下左右四个方向遍历求连通1的数目+1（当前1的数目）。
*/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int res=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==1)//当前是1再搜索
                    res=max(res,dfs(grid,i,j));//记录最大值
        return res;
    }
    int dfs(vector<vector<int>>& grid,int i,int j)
    {
        int m=grid.size();
        int n=grid[0].size();
        //边界条件
        if(i<0||i>=m||j<0||j>=n||grid[i][j]==0)
            return 0;
        grid[i][j]=0;//防止重复计数
        //搜索上下左右的1数目+自身的1
        return dfs(grid,i+1,j)+dfs(grid,i-1,j)+dfs(grid,i,j+1)+dfs(grid,i,j-1)+1;
    }
};
