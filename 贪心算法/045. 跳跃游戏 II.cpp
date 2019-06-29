/*
给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
你的目标是使用最少的跳跃次数到达数组的最后一个位置。
示例:

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
说明:

假设你总是可以到达数组的最后一个位置。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jump-game-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    int jump(vector<int>& nums) {
        int res=0;
        int size=nums.size();
        if(size==1)
            return 0;//预判断 当起点终点重合时 不需跳跃
        int maxIndex=0;//当前所在的位置
        int max=maxIndex;//下个要跳去的位置
        while(maxIndex<size)//当前位置未到达终点
        {
            if(nums[maxIndex]+maxIndex>=size-1)//若当前位置可直接到达终点
            {
                res++;//跳跃次数+1
                break;//退出循环
            }
            max=maxIndex+1;//当前位置的下一个位置
            for(int i=maxIndex+2;i<=maxIndex+nums[maxIndex];i++)//遍历当前位置能跳到的位置
                if(nums[i]+i>nums[max]+max)//索引+跳跃距离=可达位置 
                    max=i;//找当前位置能跳到的位置中 可达位置最远的那个
            maxIndex=max;//当前位置更新
            res++;//跳跃次数更新
            
        }
        /*从后往前跳 O（n*n）超时 通过91/92个case
        //实际上两个算法的时间复杂度应该相同 但是测试样例不适合从后向前的思路
        int size=nums.size();
        int minIndex=size-1;
        int min=minIndex;
        int res=0;
        while(minIndex!=0)
        {
            for(int i=minIndex-1;i>=0;i--)
            {
                if(nums[i]>=minIndex-i)
                    min=i;
            }
            minIndex=min;
            res++;
        }*/
        return res;
    }
};

