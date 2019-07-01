/*
给出一个无重叠的 ，按照区间起始端点排序的区间列表。
在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
示例 1:
输入: intervals = [[1,3],[6,9]], newInterval = [2,5]
输出: [[1,5],[6,9]]

示例 2:
输入: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
输出: [[1,2],[3,10],[12,16]]
解释: 这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/insert-interval
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;//返回结果
        if(intervals.empty())//原区间空
        {
            res.push_back(newInterval);//添加新区间
            return res;//返回 退出
        }
        auto itr=intervals.begin();//遍历原区间
        auto start=intervals.begin();//合并区间的开始
        while(itr!=intervals.end())//遍历原区间
        {
            if((*itr)[1]<newInterval[0])//新区间与当前区间无法合并
                itr++;//向后遍历
            else//新区间与当前区间可以合并
            {
                start=intervals.insert(itr,newInterval);//新区间插入到当前区间之前
                break;//退出循环
            }
        }
        if(itr==intervals.end())//新区间不能与当前区间的任意一个合并
        {
            res=intervals;//复制原区间
            res.push_back(newInterval);//末尾添加新区间
            return res;//返回 退出
        }
        itr=intervals.begin();//迭代器置为起始
        while(itr!=intervals.end())
        {
            if(itr!=start)//合并区间之前的区间
                res.push_back(*itr);//直接放入结果
            else//到达合并区间的开始
            {
                vector<int> temp=*itr;//记录当前区间
                while(itr!=intervals.end())//一直向后合并 直到不能合并为止
                {
                    if(!merge(temp,*itr))//合并区间与当前区间不能合并
                        break;//退出循环
                    itr++;//否则迭代器后移 一直合并
                }
                res.push_back(temp);//将合并区间放入结果
                while(itr!=intervals.end())//遍历合并区间之后的所有区间
                {
                    res.push_back(*itr);//放入结果
                    itr++;//迭代器后移
                }
                break;//结束合并 退出
            }
            itr++;//迭代器后移
        }
        return res;
    }
    bool merge(vector<int>& arr1,vector<int>& arr2)//辅助函数 合并两个区间
    {
        if(arr1[1]<arr2[0||arr2[1]<arr1[0]])//不能合并
            return false;//返回false
        arr1[0]=min(arr1[0],arr2[0]);//合并区间的起点是两个区间起点的最小值
        arr1[1]=max(arr1[1],arr2[1]);//合并区间的终点是两个区间终点的最大值
        return true;//返回true
    }
};
