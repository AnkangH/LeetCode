/*
给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
示例:
输入:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
输出: 6
*/


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()||matrix[0].empty())
            return 0;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> heights(n);
        int areaMax=0;
        for(int i=0;i<m;i++)//以每一行更新当前柱状图高度
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='1')
                    heights[j]++;//连续的1 高度+1
                else
                    heights[j]=0;//当前为0 则当前柱子高度为0
            }
            int areaCur=maxLineArea(heights);//当前最大面积
            areaMax=max(areaMax,areaCur);//更新最大面积
        }
        return areaMax;
    }
    int maxLineArea(vector<int> heights)//计算一行的柱状图高度
    {
        heights.push_back(0);
        int n=heights.size();
        stack<int> s;
        int areaMax=0;
        for(int i=0;i<n;i++)//单调栈 每个柱子入栈
        {
            while(!s.empty()&&heights[s.top()]>=heights[i])//柱子高度小于等于栈顶
            {
                int hCur=heights[s.top()];//上个柱子高度
                s.pop();//出栈
                int areaCur=s.empty()?hCur*i:hCur*(i-s.top()-1);//如果栈空 则上个柱子高度*i 否则*i-上上个柱子高度-1
                areaMax=max(areaMax,areaCur);
            }
            s.push(i);//当前柱子入栈
        }
        return areaMax;
    }
};
