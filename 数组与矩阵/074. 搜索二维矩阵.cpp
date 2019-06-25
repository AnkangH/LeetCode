/*
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。
示例 1:
输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
输出: true
示例 2:
输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
输出: false
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-a-2d-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;//注意空矩阵 求下面的n会超索引
        int m=matrix.size();
        int n=matrix[0].size();
        int r=0;//第一行
        int c=n-1;//最后一列
        while(r<m&&c>=0)//从左上或者右下开始搜索 因此此时大小对应的移动方向唯一
        {
            if(target==matrix[r][c])//找到 target
                return true;//返回true退出
            else if(target>matrix[r][c])//当前值较小
                r++;// 向下移动
            else//当前值较大 
                c--;//向左移动
        }
        return false;//wehile循环退出 未返回true 则不存在
    }
};
