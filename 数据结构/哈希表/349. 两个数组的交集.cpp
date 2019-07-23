/*
给定两个数组，编写一个函数来计算它们的交集。
示例 1:
输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2]
示例 2:
输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [9,4]
说明:
输出结果中的每个元素一定是唯一的。
我们可以不考虑输出结果的顺序。
*/


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if(nums1.empty()&&!nums2.empty())
            return res;//1空2非空 交集为空 
        if(!nums1.empty()&&nums2.empty())
            return res;//1非空2空 交集为空
        unordered_map<int,int> m;
        for(auto p:nums1)
            if(m.count(p)==0)//只记录在数组1中第一次出现
                m[p]++;
        for(auto p:nums2)
            if(m.count(p)!=0&&m.find(p)->second==1)//只记录在数组2中第一个查找到
            {
                res.push_back(p);
                m[p]++;
            }
        return res;
    }
};
