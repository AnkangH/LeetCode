/*
给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的绝对值最大为 k。
示例 1:
输入: nums = [1,2,3,1], k = 3
输出: true
示例 2:
输入: nums = [1,0,1,1], k = 1
输出: true
示例 3:
输入: nums = [1,2,3,1,2,3], k = 2
输出: false
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/contains-duplicate-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int res=INT_MAX;//记录重复数字的最小间隔
        unordered_map<int,int> m;//哈希表
        int size=nums.size();//数组大小
        for(int i=0;i<size;i++)//因为需要索引值 所以使用索引遍历
        {
            if(m.count(nums[i])==0)//未出现
                m[nums[i]]=i;//记录第一次出现索引
            else//已出现
            {
                res=min(res,i-m.find(nums[i])->second);//保存最小间隔
                m[nums[i]]=i;//更新索引
            }
        }
        return res<=k? true:false;//返回值
    }
};
