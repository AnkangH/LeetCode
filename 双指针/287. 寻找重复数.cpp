/*
给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。
示例 1:
输入: [1,3,4,2,2]
输出: 2
示例 2:
输入: [3,1,3,4,2]
输出: 3
说明：
不能更改原数组（假设数组是只读的）。
只能使用额外的 O(1) 的空间。
时间复杂度小于 O(n2) 。
数组中只有一个重复的数字，但它可能不止重复出现一次。
*/


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int f=0,s=0;//快慢指针的起点
        while(1)
        {
            f=nums[nums[f]];//快指针每次走两步
            s=nums[s];//慢指针每次走一步
            if(f==s)//有环
            {
                s=0;//慢指针从0开始走
                while(f!=s)//直到两个指针相等
                {
                    f=nums[f];//走一步
                    s=nums[s];//走一步
                }
                return f;//环的入口
            }
        }
        return -1;
    }
};
