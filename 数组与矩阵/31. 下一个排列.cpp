/*
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
必须原地修改，只允许使用额外常数空间。
以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-permutation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size=nums.size();
        bool change=false;
        for(int i=size-2;i>=0;i--)//i从数组倒数第二个开始向前 
        {
            int minVal=INT_MAX;//记录比nums[i]大的数字中最小的值
            int minIndex=INT_MAX;//记录比nums[i]大的数字中最小值对应的索引
            for(int j=i+1;j<size;j++)//j从i开始向后找
            {
                if(nums[j]>nums[i])//找到比nums[i]大的数字
                {
                    if(nums[j]<minVal)//保存其中的最小值及索引
                    {
                        minIndex=j;
                        minVal=nums[j];
                    }
                }
            }
            if(minIndex!=INT_MAX)//找到比nums[i]大的数字
            {
                int temp=nums[i];//交换nums[i] nums[j]的值
                nums[i]=nums[minIndex];
                nums[minIndex]=temp;
                auto start=nums.begin()+i+1;
                sort(start,nums.end());//将nums[i]之后的数组排序
                change=true;//记录已修改数组
                break;
            }
        }
        if(!change)//如果未找到比nums[i]大的数字 说明原数组降序排序 反转即可
            reverse(nums.begin(),nums.end());
    }
};
