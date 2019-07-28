/*
给你一个由若干 0 和 1 组成的二维网格 grid，请你找出边界全部由 1 组成的最大 正方形 子网格，并返回该子网格中的元素数量。如果不存在，则返回 0。
示例 1：
输入：grid = [[1,1,1],[1,0,1],[1,1,1]]
输出：9
示例 2：
输入：grid = [[1,1,0,0]]
输出：1
提示：
1 <= grid.length <= 100
1 <= grid[0].length <= 100
grid[i][j] 为 0 或 1
*/


class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;//边界条件空矩阵 返回0
        vector<vector<int>> dp1=grid;//以i,j为起点向右下放射的最大长度
        vector<vector<int>> dp2=grid;//以i,j为起点向左上放射的最大长度
        int m=grid.size();//行
        int n=grid[0].size();//列
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)//构建dp1和dp2
            {
                int x=i,y=j;//当前索引
                int xl=0,yl=0;//向右和向下放射的长度
                while(x<m)//求向下放射的最大长度
                {
                    if(grid[x][y]==1)
                        xl++;
                    else
                        break;
                    x++;
                }
                x=i;//当前索引
                while(y<n)//求向右放射的最大长度
                {
                    if(grid[x][y]==1)
                        yl++;
                    else
                        break;
                    y++;
                }
                dp1[i][j]=min(xl,yl);//取右下放射长度的最小值 记录dp1
                //cout<<"dp1 "<<i<<j<<"="<<dp1[i][j]<<endl;
                x=i,y=j;//当前索引
                xl=0,yl=0;//放射长度归零
                while(x>=0)//求向上放射的最大长度
                {
                    if(grid[x][y]==1)
                        xl++;
                    else
                        break;
                    x--;
                }
                x=i;//当前索引
                while(y>=0)//求左放射的最大长度
                {
                    if(grid[x][y]==1)
                        yl++;
                    else
                        break;
                    y--;
                }
                dp2[i][j]=min(xl,yl);//向上和向左放射长度的最小值 记录dp2
                //cout<<"dp2 "<<i<<j<<"="<<dp2[i][j]<<endl;
            }
        int res=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)//遍历矩阵元素 作为正方型的左上角点
            {
                //cout<<i<<j<<endl;
                if(grid[i][j]!=0)//左上角点不为0
                {
                    for(int k=dp1[i][j];k>=1;k--)//从最大长度开始递减
                        if(dp2[i+k-1][j+k-1]>=k)//能构成正方形
                        {
                            res=max(res,k*k);//求最大正方形的元素个数
                            break;
                        }
                }
            }
        return res;
    }
};
