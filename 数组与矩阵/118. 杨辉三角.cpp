/*
给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
在杨辉三角中，每个数是它左上方和右上方的数的和。
示例:
输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pascals-triangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows==0)
            return res;//边界条件 n==0
        res.push_back({1});
        if(numRows==1)
            return res;//边界条件 n==1
        res.push_back({1,1});
        if(numRows==2)
            return res;//边界条件 n==2
        vector<int> pre={1,1};//前一行
        for(int i=2;i<numRows;i++)//后n-2行
        {
            vector<int> temp(i+1,1);//当前行
            for(int j=1;j<i;j++)//修改第2个数到倒数第2个数
                temp[j]=pre[j-1]+pre[j];//每个数的值为上一行对应两个数的和
            res.push_back(temp);//当前行放入结果
            pre=temp;//更新上一行
        }
        return res;
    }
};
