/*
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
示例 1:
给定 nums = [1,1,1,2,2,3],
函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。
你不需要考虑数组中超出新长度后面的元素。
示例 2:
给定 nums = [0,0,1,1,1,1,2,3,3],
函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。
你不需要考虑数组中超出新长度后面的元素。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index=1,cnt=1;//数组第一个元素不用修改  index指修改后的索引 cnt记录当前数字的个数
        int size=nums.size();
        if(size==0)
            return 0;//数组空 返回0 否则下面访问越界
        if(size==1)
            return 1;//数组只有一个元素 返回1 否则下面访问越界
        for(int i=1;i<size;i++)//遍历数组
        {
            if(nums[i]!=nums[i-1])//与前一个不相同
            {
                nums[index]=nums[i];//将当前数字放到修改后的位置
                index++;//移动修改后的位置
                cnt=1;//记录当前数字的个数
            }
            else//与前一个数字相同
            {
                if(cnt<2)//如果当前数字计数小于2
                {
                    nums[index]=nums[i];//放入修改后的位置
                    cnt++;//当前数字个数增加
                    index++;//修改后的索引移动
                } 
            }
        }
        return index;//index记录符合要求的数字 从1开始增加 因此返回index即可
    }
};
