/*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和.
假定每组输入只存在唯一答案。
例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum-closest
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size=nums.size();
        int minVal=INT_MAX;//最接近target的三数和
        int minDif=INT_MAX;//记录两数和的最小差值
        sort(nums.begin(),nums.end());//排序
        for(int i=0;i<size;i++)
        {
            if(i>0&&nums[i]==nums[i-1])
                continue;//跳过相同的nums[i]
            int l=i+1,r=size-1;//对i之和的数组进行双指针求两数和
            int want=target-nums[i];//两数之和的目标值
            while(l<r)
            {
                bool flag=false;//重复组合标志位
                if(l>i+1&&nums[l]==nums[l-1])//左指针与上个重复 移动左指针
                {
                    l++;
                    flag=true;
                }
                if(r<size-1&&nums[r]==nums[r+1])//右指针与上个重复 移动右指针
                {
                    r--;
                    flag=true;
                }
                if(l>=r)
                    break;//上述移动左右指针可能提前使l和r越界
                if(flag)
                    continue;//若有重复指针 跳过本轮判断
                if(nums[l]+nums[r]<want)//两数之和小于目标值
                {
                    
                    int dif=abs(want-nums[l]-nums[r]);//记录当前差值的绝对值
                    if(dif<minDif)
                    {
                        minDif=dif;//保存较小差值
                        minVal=nums[i]+nums[l]+nums[r];//保存最接近目标值的三数之和
                    }
                    l++;
                }
                else if(nums[l]+nums[r]==want)//两数之和等于目标值
                    return target;//返回目标值 提前结束
                else//两数之和大于目标值
                {
                    int dif=abs(want-nums[l]-nums[r]);//记录当前差值的绝对值
                    if(dif<minDif)
                    {
                        minDif=dif;//保存较小差值
                        minVal=nums[i]+nums[l]+nums[r];//保存最接近目标值的三数之和
                    }
                    r--;
                }
            }
        }
        return minVal;
    }
};
