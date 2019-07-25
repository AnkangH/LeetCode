/*
给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
示例 1:
输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:
输入: nums = [1], k = 1
输出: [1]
说明：

你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
*/


class Solution {
public:
    struct cmp
    {
        bool operator()(vector<int> a,vector<int> b)
        {
            return a[1]>b[1];//以vector<int>的第二个元素比较大小 构建小顶堆
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto p:nums)
            m[p]++;
        priority_queue<vector<int>,vector<vector<int>>,cmp> st;//小顶堆
        for(auto p:m)
            st.push(vector<int>{p.first,p.second});//所有出现的数字 按照出现次数入堆
        int size=st.size();
        while(size>k)//堆中元素>k
        {
            st.pop();//堆顶出堆
            size=st.size();
        }
        vector<int> res;
        while(!st.empty())//堆中剩余k个为出现次数最多的元素
        {
            res.push_back(st.top()[0]);//放入结果
            st.pop();
        }
        return res;
    }
};
