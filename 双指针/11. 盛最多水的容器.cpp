/*
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
说明：你不能倾斜容器，且 n 的值至少为 2。
图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
示例:
输入: [1,8,6,2,5,4,8,3,7]
输出: 49
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/container-with-most-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//
class Solution {
public:
    int maxArea(vector<int>& height) {
        int size=height.size();
        int volum=0;
        int left=0,right=size-1;
        while(left<right)
        {
            int area=(right-left)*min(height[left],height[right]);//求当前面积
            volum=max(volum,area);//记录最大面积
            //边的高度的变换对容积的影响要大于每次移动边界造成的底边长度减1 所以这种方法是正确的
            if(height[left]<height[right])//将较矮的一边向较高的一边移动 相等时 移动哪一边均可
                left++;
            else
                right--;
            
        }
        /*暴力法超时
        for(int i=0;i<size;i++)
            for(int j=i+1;j<size;j++)
            {
                volum=max(volum,(j-i)*min(height[i],height[j]));
            }*/
        return volum;
    }
};
