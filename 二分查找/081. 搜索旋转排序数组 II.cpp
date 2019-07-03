/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。
( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。
编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。
示例 1:
输入: nums = [2,5,6,0,0,1,2], target = 0
输出: true
示例 2:
输入: nums = [2,5,6,0,0,1,2], target = 3
输出: false
进阶:
这是 搜索旋转排序数组 的延伸题目，本题中的 nums  可能包含重复元素。
这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int size=nums.size();
        int l=0,r=size-1;
        while(l<=r)
        {
            while(l+1<=r&&nums[l]==nums[l+1])
                l++;//跳过l重复元素
            while(r-1>=l&&nums[r]==nums[r-1])
                r--;//跳过r重复元素
            int mid=(r-l)/2+l;
            if(nums[mid]==target)
                return true;//找到目标值 退出
            else
            {
                if(nums[mid]<=nums[r])//右侧有序
                {
                    if(target>nums[mid]&&target<=nums[r])//在右侧有序范围内
                        l=mid+1;//搜索右侧
                    else //不在有序范围内
                        r=mid-1;//搜索左侧
                }
                else //左侧有序
                {
                    if(target>=nums[l]&&target<nums[mid])//在左侧有序范围内
                        r=mid-1;//搜索左侧
                    else//不在有序范围内
                        l=mid+1;//搜索左侧
                }
            }
        }
        return false;//不在数组内
    }
};
