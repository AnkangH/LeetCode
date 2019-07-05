/*
给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
在杨辉三角中，每个数是它左上方和右上方的数的和。
示例:
输入: 3
输出: [1,3,3,1]
进阶：
你可以优化你的算法到 O(k) 空间复杂度吗？
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pascals-triangle-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1,1);//索引从0开始 所以共index+1个数字
        if(rowIndex==0||rowIndex==1)
            return res;
        for(int i=2;i<rowIndex+1;i++)//从第3行开始修改
        {
            int pre=res[0];//第一个前值
            for(int j=1;j<i;j++)//每次修改i+1个数字中，第2个到倒数第2个的值 模拟杨辉三角的递推过程
            {
                int temp=res[j];//因为res[j]未修改前的值要作为下一次的加数 所以提前保存
                res[j]=res[j]+pre;//更新当前值为上一行两个数字之和
                pre=temp;//更新前值
            }
        }
        return res;
    }
};
