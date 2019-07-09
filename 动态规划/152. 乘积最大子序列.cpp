/*
给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。
示例 1:
输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:
输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int curMax=nums[0],curMin=nums[0];//前i个的最大和最小连续乘积
        int res=nums[0];//最终结果 保存最大乘积
        for(int i=1;i<n;i++)
        {
            int a=curMax*nums[i];//前i-1个的最大乘积*当前值
            int b=curMin*nums[i];//前i-1个的最小乘积*当前值
            curMax=max(nums[i],max(a,b));//用三者的最大值更新当前最大值
            curMin=min(nums[i],min(a,b));//用三者的最小值更新当前最小值
            res=max(res,curMax);//保存最大乘积
        }
        return res;
    }
};
