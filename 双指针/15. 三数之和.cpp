/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
注意：答案中不可以包含重复的三元组。
例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size=nums.size();
        vector<vector<int>> res;
        if(size<3)
            return res;
        sort(nums.begin(),nums.end()); 
        for(int i=0;i<size;i++)
        {
            if(i>0&&nums[i]==nums[i-1])
                continue;//相同的数字不再求两数之和 因为肯定与之前的重复
            int target=-nums[i];//两数之和
            int l=i+1,r=size-1;//左右指针
            while(l<r)
            {
                bool flag=false;//记录当前值与上一个值是否相同 
                if(l>i+1&&nums[l]==nums[l-1])//判断左指针当前值是否重复
                {
                    l++;
                    flag=true;
                }
                if(r<size-1&&nums[r]==nums[r+1])//判断右指针是否重复
                {
                    r--;
                    flag=true;
                }
                if(l>=r)
                    break;//判断时l++，r--可能提前到达循环结束条件 若不退出 下面会数组越界
                if(flag)
                    continue;//若左右指针任意一个与上一个值重复 跳过本轮判断
                if(nums[l]+nums[r]<target)
                    l++;//两数之和小于目标值 左指针向右移动 增大和
                else if(nums[l]+nums[r]>target)
                    r--;//两数之和大于目标值 右指针向左移动 减小和
                else
                {
                    res.push_back({nums[i],nums[l],nums[r]});//因为数组有序 又l<r;l=i+1,所以i<l 所以按照索引升序即可
                    l++;//左指针移动
                    r--;//右指针移动
                }
                
            }
        }
        return res;
    }
};
