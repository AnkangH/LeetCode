/*
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
示例 1:
给定数组 nums = [1,1,2], 
函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。 
你不需要考虑数组中超出新长度后面的元素。
示例 2:
给定 nums = [0,0,1,1,1,2,2,3,3,4],
函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
你不需要考虑数组中超出新长度后面的元素。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int size=nums.size();
        int pre=nums[0];//首个数字一定符合
        int cnt=1;//记录不重复数字
        for(int i=1;i<size;i++)
        {
            if(nums[i]<=pre)//当前值小于前一个值
                for(int j=i+1;j<size;j++)//向后寻找
                {
                    if(nums[j]>pre)//第一个比前一个值大的数字
                    {
                        nums[i]=nums[j];//修改当前值
                        pre=nums[j];//前值更新
                        cnt++;//计数更新
                        break;//只找第一个 找到后退出该循环
                    }
                }
            else//当前值比前值大
            {
                pre=nums[i];//修改前值
                cnt++;//计数更新
            }
        }
        return cnt;
    }
};
