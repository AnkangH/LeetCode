/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
示例:
输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;//当前和
        int res=INT_MIN;//结果
        int size=nums.size();
        for(int i=0;i<size;i++)//遍历数组
        {
            sum+=nums[i];//当前数字加入当前和
            res=max(res,sum);//保存当前和的最大值
            if(sum<0)//若sum小于0 则最大和一定不包含此时的当前和sum
                sum=0;//当前和sum清零 
        }
        return res;//返回最大和
    }
};
