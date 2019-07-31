/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。
示例:
输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6
*/


class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> dpLeft(n,0);//第i个柱子左侧的最大高度
        vector<int> dpRight(n,0);//第i个柱子右侧的最大高度
        vector<int> dp(n,0);//第i个柱子能接的雨水
        for(int i=1;i<n;i++)//柱子左侧的最大高度 从左向右遍历 i=0时为0
            dpLeft[i]=max(dpLeft[i-1],height[i-1]);//上一个柱子左侧的最大高度和其高度的较大值
        for(int i=n-2;i>=0;i--)//柱子右侧的最大高度 从右向左遍历 i=n-1时为0
            dpRight[i]=max(dpRight[i+1],height[i+1]);//上一个柱子右侧的最大高度和其高度的较大值
        int res=0;//总的雨水值
        for(int i=0;i<n;i++)//遍历每个柱子
        {
            dp[i]=min(dpLeft[i],dpRight[i])-height[i];//左右两侧最大高度中的较小者-柱子高度
            if(dp[i]>0)
                res+=dp[i];//能接雨水  总雨水值更新
        }
        return res;
    }
};
