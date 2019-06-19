/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
你可以假设数组中无重复元素。
示例 1:
输入: [1,3,5,6], 5
输出: 2
示例 2:
输入: [1,3,5,6], 2
输出: 1
示例 3:
输入: [1,3,5,6], 7
输出: 4
示例 4:
输入: [1,3,5,6], 0
输出: 0
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-insert-position
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size=nums.size();
        int l=0,r=size-1;//左右指针
        while(l<=r)//搜索时 为防止跳过 左右指针最后一次可相同
        {
            int mid=(r-l)/2+l;//向下取整 每次mid都在靠左一侧 
            if(nums[mid]<target)
                l=mid+1;
            else if(nums[mid]>target)
                r=mid-1;
            else
                return mid;//若找到target 返回索引
        }
        nums.emplace(nums.begin()+l,target);//若未找到target 在最后搜索位置插入target
        return l;//返回插入的索引
    }
};
