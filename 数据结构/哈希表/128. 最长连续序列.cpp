/*
给定一个未排序的整数数组，找出最长连续序列的长度。
要求算法的时间复杂度为 O(n)。
示例:
输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-consecutive-sequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;
        unordered_map<int,int> m;//记录每个数字的连续子序列长度
        int res=INT_MIN;//返回结果
        for(auto p:nums)//遍历数组
        {
            if(m.count(p)==1)
                continue;//已经有的元素不会影响连续序列长度 跳过
            int left=0,right=0;
            if(m.count(p-1)!=0)
                left=m.find(p-1)->second;//当前数字左侧连续序列的长度
            if(m.count(p+1)!=0)
                right=m.find(p+1)->second;//当前数字右侧连续序列的长度
            int cur=left+right+1;//当前数字的连续长度
            res=max(res,cur);//记录最大连续长度
            m[p]=cur;//修改当前数字的连续长度
            m[p-left]=cur;//修改连续区间首元素的值为当前连续序列的元素个数
            m[p+right]=cur;//修改尾元素
        }
        return res;
    }
};
