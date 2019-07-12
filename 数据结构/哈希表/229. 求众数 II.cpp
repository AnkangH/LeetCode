/*
给定一个大小为 n 的数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。
说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1)。
示例 1:
输入: [3,2,3]
输出: [3]
示例 2:
输入: [1,1,1,3,3,2,2,2]
输出: [1,2]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/majority-element-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        n/=3;//目标值
        unordered_map<int,int> m;//记录每个数字出现次数
        vector<int> res;
        for(auto p:nums)//遍历数组
        {
            m[p]++;//哈希表出现次数增加
            if(m.find(p)->second==n+1)//只有第一次超过n时放入，防止重复放入
                res.push_back(p);
        }
        return res;
    }
};
