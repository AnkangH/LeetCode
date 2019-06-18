/*
给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
示例 1:
给定 nums = [3,2,2,3], val = 3,
函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
你不需要考虑数组中超出新长度后面的元素。
示例 2:
给定 nums = [0,1,2,2,3,0,4,2], val = 2,
函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
注意这五个元素可为任意顺序。
你不需要考虑数组中超出新长度后面的元素。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       if(nums.empty())
           return 0;
        int size=nums.size();
        int l=0,r=size-1,cnt=0;//左右指针和计数
        while(l<=r)//=号是因为当l和r相遇时，如果该数字不等于val 那么cnt应该+1 或者使用l<r进行while 但是当循环退出后，l=r，判断数组该数字是否等于val 并对cnt进行修改
        {
            if(nums[l]==val&&nums[r]!=val)//左为val，右不为val
            {
                nums[l]=nums[r];
                nums[r]=val;//交换l和r对应的元素
                l++;//l移动
                r--;//r移动
                cnt++;//计数增加
            }
            else if(nums[l]!=val&&nums[r]==val)//左不为val 右为val 上面修改了l和r 所以每个if语句应该互斥
            {
                l++;//l移动
                r--;//r移动
                cnt++;//计数增加
            }
            else if(nums[l]==val&&nums[r]==val)//左为val 右为val
            {
                r--;//l不动 r移动因为后面为val是正确的 而前面为val一定要移动到后面去 所以l不动
            }
            else if(nums[l]!=val&&nums[r]!=val)//左不为val 右不为val
            {
                l++;//左的位置正确 l移动判断下一个 r不为val不正确 r不移动
                cnt++;//计数增加
            }
        }
        return cnt;
    }
};
