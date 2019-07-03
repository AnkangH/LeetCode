/*
给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
示例:
输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int start=0;//每一轮的起点
        int cnt=1;//当前元素的值
        vector<vector<int>> res(n,vector<int>(n,0));//nxn矩阵 初值0
        while(n>0)//剩余的行大于0 仍需更新
        {
            int i=start,j=start;//当前轮的遍历索引 i行 j列
            for(j;j<start+n;j++)//向右移动
            {
                res[i][j]=cnt;
                cnt++;
            }
            j--;//列复原到最后一列 此时位于（右上角点）
            i++;//行更新到下一行   防止右上角点重复修改
            for(i;i<start+n;i++)
            {
                res[i][j]=cnt;
                cnt++;
            }
            i--;//行复原到最后一行 此时位于右下角点
            j--;//列更新上下一列  防止右下角点重复修改
            for(j;j>=start;j--)
            {
                res[i][j]=cnt;
                cnt++;
            }
            j++;//列复原到第一列  此时位于左下角点
            i--;//行更新到上一行  防止左下角点重复修改
            for(i;i>start;i--)
            {
                res[i][j]=cnt;
                cnt++;
            }//此时修改置左上角点的下一行点 因为start修改 所以不需复原
            start++;//下一个对角线上的点做为起点
            n-=2;//待修改的行列数-2
            if(n==1)//只剩一行一列待修改 即下一轮只有一个点需要修改
            {
                res[start][start]=cnt;//修改该点
                break;//提前退出
            }
        }
        return res;
    }
};
