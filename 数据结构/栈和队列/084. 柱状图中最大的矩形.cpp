/*
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
求在该柱状图中，能够勾勒出来的矩形的最大面积。
以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。
图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。
示例:
输入: [2,1,5,6,2,3]
输出: 10
*/


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);//单调站最后一个为0 进行面积计算
        stack<int> s;//单调栈 存放heights的索引
        int n=heights.size();
        int maxArea=0;
        for(int i=0;i<n;i++)//单调栈 遇到高度小于栈顶的柱子 更新最大面积 栈顶出栈
        {
            while(!s.empty()&&heights[i]<=heights[s.top()])//当前矩形高小于栈顶 一直更新最大面积并出栈
            {
                int heightCur=heights[s.top()];//上一个矩形的高
                s.pop();//出栈
                int areaCur=s.empty()?heightCur*i:heightCur*(i-s.top()-1);//栈空 计算单个矩形面积 否则求相邻矩形面积
                maxArea=max(maxArea,areaCur);//更新最大矩形
            }
            s.push(i);//当前矩形索引入栈
        }
        return maxArea;
    }
};
