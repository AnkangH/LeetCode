/*
给定一个二维矩阵，计算其子矩形范围内元素的总和，该子矩阵的左上角为 (row1, col1) ，右下角为 (row2, col2)。
上图子矩阵左上角 (row1, col1) = (2, 1) ，右下角(row2, col2) = (4, 3)，该子矩形内元素的总和为 8。
示例:
给定 matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]
sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
说明:
你可以假设矩阵不可变。
会多次调用 sumRegion 方法。
你可以假设 row1 ≤ row2 且 col1 ≤ col2。
*/


class NumMatrix {
public:
    vector<vector<int>> sums;//sums[i][j] maxtrix第i行的sum(0,j)
    NumMatrix(vector<vector<int>>& matrix) {
        for(auto p:matrix)//遍历每一行
        {
            int sum=0;
            vector<int> sumLine;
            for(auto pp:p)//每一行的每一列元素
            {
                sum+=pp;//当前和
                sumLine.push_back(sum);//放入当前和之和
            }
            sums.push_back(sumLine);//每一行的sum(0,i)
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res=0;
        for(int i=row1;i<=row2;i++)//第i行
        {
            if(col1==0)
                res+=sums[i][col2];//sums(0,j)
            else
                res+=sums[i][col2]-sums[i][col1-1];//sums(0,j2)-sums(0,j1)
        }
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
