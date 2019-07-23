/*
给定两个数组，编写一个函数来计算它们的交集。
示例 1:
输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2,2]
示例 2:
输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [4,9]
说明：
输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
我们可以不考虑输出结果的顺序。
*/


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if(nums1.empty()||nums2.empty())
            return res;//有一个空 交集为空
        unordered_map<int,int> m;
        for(auto p:nums1)
            m[p]++;//记录nums1中每个元素出现次数
        for(auto p:nums2)//对nums2中每个出现元素
        {
            if(m.count(p)!=0&&m.find(p)->second>0)//出现且当前重复次数>0
            {
                res.push_back(p);//构成一个交集元素 放入交集数组中
                m[p]--;//nums1中该元素可构成交集的次数-1
            }
        }
        return res;
    }
};
