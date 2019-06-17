/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
你的算法时间复杂度必须是 O(log n) 级别。
如果数组中不存在目标值，返回 [-1, -1]。
示例 1:
输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:
输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size=nums.size();
        if(size==0)
            return {-1,-1};//预处理 空数组返回未找到
        int l=0,r=size-1;//二分法找到一个target
        int res=INT_MAX;
        while(l<=r)//注意l可以等于r，否则当数组只有一个元素时不符，或者某些位置检测不到
        {
            int mid=(r-l)/2+l;
            if(nums[mid]>target)
                r=mid-1;
            else if(nums[mid]==target)
            {
                res=mid;//若找到一个target，记录其在数组中的位置即退出循环
                break;
            }
            else
                l=mid+1;
        }
        if(res==INT_MAX)
            return {-1,-1};//数组中不含target
        else
        {
            l=res,r=res;//向两侧扩展 直到数字不为target
            while(r<size-1)//向左扩展找target的最小索引
            {
                if(nums[r+1]==target)
                    r++;
                else
                    break;
            }
            while(l>0)//向右扩展找target的最大索引
            {
                if(nums[l-1]==target)
                    l--;
                else
                    break;
            }
            return {l,r};
        }
    }
};
