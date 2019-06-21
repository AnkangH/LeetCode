/*
给出一个区间的集合，请合并所有重叠的区间。
示例 1:
输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2:
输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-intervals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());//区间按照起始值排序
        int size=intervals.size();
        vector<vector<int>> res;
        if(size==0)
            return res;//预处理 防止空数组
        vector<int> temp=intervals[0];//当前区间初始化为起始值最小区间
        for(int i=1;i<size;i++)//遍历区间数组
        {
            if(intervals[i][0]<=temp[1])//可以合并
                temp={temp[0],max(temp[1],intervals[i][1])};//由于起始值已排序 所以合并区间的起始值为temp的起始值 区间终点为两个终点中的最大值
            else//不可合并
            {
                res.push_back(temp);//将上个区间放入结果
                temp=intervals[i];//更新当前区间
            }
        }
        res.push_back(temp);//将最后的temp放入res 因为上述循环结束后 最后的一个区间还没有放入res
        return res;
    }
};
