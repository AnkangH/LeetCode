/*
峰值元素是指其值大于左右相邻值的元素。
给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。
数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。
你可以假设 nums[-1] = nums[n] = -∞。
示例 1:
输入: nums = [1,2,3,1]
输出: 2
解释: 3 是峰值元素，你的函数应该返回其索引 2。
示例 2:
输入: nums = [1,2,1,3,5,6,4]
输出: 1 或 5 
解释: 你的函数可以返回索引 1，其峰值元素为 2；
     或者返回索引 5， 其峰值元素为 6。
说明:
你的解法应该是 O(logN) 时间复杂度的。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-peak-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size=nums.size();
        int l=0,r=size-1;//左右指针
        while(l<r)//l<r 这样退出时l=r 即最后一次查找才找到结果 
        {
            int mid=(r-l)/2+l;//二分
            if(mid==0)//边界条件 当mid==0时，只有mid+1合法
            {
                if(nums[mid]>nums[mid+1])//又有nums[-1]=-∞
                    return mid;//nums[mid]为一个极值
                else
                    l=mid+1;//搜索大数所在的范围
            }
            else if(mid==size-1)//边界条件 当mid==size-1时 只有mid-1合法
            {
                if(nums[mid]>nums[mid-1])//又有nums[size]=-∞
                    return mid;//nums[mid]为一个极值的
                else
                    r=mid-1;//搜索大数所在的范围
            }
            else//mid-1和mid+1均合法时
            {
                if(nums[mid]>nums[mid+1]&&nums[mid]>nums[mid-1])
                    return mid;//当前是一个极值 
                else if(nums[mid]<nums[mid+1])//若左右都有极值 则优先右侧
                    l=mid+1;//搜索右侧
                else
                    r=mid-1;//搜索左侧
            }
        }
        return l;//最后一次查找才发现极值 返回其索引
    }
};
