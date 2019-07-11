/*
给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。
你可以假设网格的四个边均被水包围。
示例 1:
输入:
11110
11010
11000
00000
输出: 1
示例 2:
输入:
11000
11000
00100
00011
输出: 3
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-islands
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    int m,n;
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
            return 0;//预处理 矩阵空返回0
        int res=0;//计数结果
        m=grid.size();//行数
        n=grid[0].size();//列数
        for(int i=0;i<m;i++)//遍历行
            for(int j=0;j<n;j++)//遍历列
                if(grid[i][j]=='1')//当前为1
                {
                    res++;//计数增加
                    dfs(grid,i,j);//将上下左右搜索到的1全修改为0
                }
        return res;
    }
    void dfs(vector<vector<char>>& grid,int l,int r)
    {
        if(l<0||l>=m||r<0||r>=n||grid[l][r]=='0')//超范围或当前不为1 
            return;//退出当前函数
        grid[l][r]='0';//将当前的1改为0 防止重复遍历
        dfs(grid,l+1,r);//搜索右
        dfs(grid,l-1,r);//搜索左
        dfs(grid,l,r+1);//搜索下
        dfs(grid,l,r-1);//搜索上
    }
};

