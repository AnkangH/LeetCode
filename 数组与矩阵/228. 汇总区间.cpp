/*
给定一个无重复元素的有序整数数组，返回数组区间范围的汇总。
示例 1:
输入: [0,1,2,4,5,7]
输出: ["0->2","4->5","7"]
解释: 0,1,2 可组成一个连续的区间; 4,5 可组成一个连续的区间。
示例 2:
输入: [0,2,3,4,6,8,9]
输出: ["0","2->4","6","8->9"]
解释: 2,3,4 可组成一个连续的区间; 8,9 可组成一个连续的区间。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/summary-ranges
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.empty())
            return res;//预处理 空数组直接返回
        int pre=nums[0],start=nums[0];//区间起点start和终点pre的初始值
        int size=nums.size();
        for(int i=1;i<size;i++)//向后遍历
        {
            if(nums[i]>1+pre)//不连续
            {
                if(start==pre)
                    res.push_back(to_string(start));//只有一个值
                else
                    res.push_back(to_string(start)+"->"+to_string(pre));//起点和终点区间
                start=nums[i];//更新起点值
            }
            pre=nums[i];//更新终点值
        }//退出后 最后一个区间还没有放入结果
        if(start==pre)
            res.push_back(to_string(start));//单值区间
        else
            res.push_back(to_string(start)+"->"+to_string(pre));//区间起点和终点值
        return res;
    }
};
