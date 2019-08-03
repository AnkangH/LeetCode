/*
给定一个未排序的整数数组，找出其中没有出现的最小的正整数。
示例 1:
输入: [1,2,0]
输出: 3
示例 2:
输入: [3,4,-1,1]
输出: 2
示例 3:
输入: [7,8,9,11,12]
输出: 1
说明:
你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。
*/


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n)
        {
            if(nums[i]<=0||nums[i]>n||nums[i]==i+1||nums[nums[i]-1]==nums[i])//超范围 当前正确 待交换的正确 都不需交换
            {
                i++;//跳到下一个需要交换的位置
                continue;//跳过交换语句
            }
            int temp=nums[nums[i]-1];//当前值正确位置处的值 保存
            nums[nums[i]-1]=nums[i];//当前值放到数组正确位置
            nums[i]=temp;//正确位置处的值放到当前位置
        }
        for(int i=0;i<n;i++)
            if(nums[i]!=i+1)
                return i+1;//该数字未出现
        return n+1;//1~n均已出现 返回n+1
    }
};
