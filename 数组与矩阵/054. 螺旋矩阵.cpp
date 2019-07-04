/*
给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1:
输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]

示例 2:
输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return {};//边界条件 空矩阵 返回空
        int m=matrix.size();//剩余待遍历行数
        int n=matrix[0].size();//剩余待遍历列数
        int start=0;//当前轮起始点 (start,start)
        vector<int> res;//返回值
        if(m<2)
            return matrix[0];//只有一行 返回该行即可 1行1列也满足该条件
        else if(n<2)//只有一列
        {
            for(auto p:matrix)
                res.push_back(p[0]);//从上往下放入列元素
            return res;//返回
        }
        while(m>0&&n>0)//下面的while循环最少处理两行两列 否则会重复添加
        {
            int i=start,j=start;//当前起点
            for(j;j<start+n;j++)
                res.push_back(matrix[i][j]);//向右遍历
            j--;//j复原 此时位于右上角点
            i++;//i向下移动 防止重复添加右上角点
            for(i;i<start+m;i++)
                res.push_back(matrix[i][j]);//向下遍历
            i--;//同理i复原
            j--;//j跳过已遍历的点
            for(j;j>=start;j--)
                res.push_back(matrix[i][j]);//向左遍历
            j++;//j复原
            i--;//i跳过已遍历的点
            for(i;i>start;i--)
                res.push_back(matrix[i][j]);//向上遍历 遍历后若进入下一轮 i和j重新赋值 因此不需复原
            m-=2;//每一轮遍历两行
            n-=2;//每一轮遍历两列
            start++;//起点跳向下一个对角线上的点
            if(m==1)//只剩一行待遍历
            {
                i=start,j=start;//下个起点
                for(j;j<start+n;j++)
                    res.push_back(matrix[i][j]);//遍历该行
                    break;//提前退出
            }
            else if(n==1)//剩余一列待遍历
            {
                i=start,j=start;//下个起点
                for(i;i<start+m;i++)
                    res.push_back(matrix[i][j]);//遍历该列
                break;//提前退出
            }
        }
        return res;
    }
};
