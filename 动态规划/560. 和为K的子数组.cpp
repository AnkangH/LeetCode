/*
给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。
示例 1 :
输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
说明 :
数组的长度为 [1, 20,000]。
数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。
*/


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> dict;
        dict[0]=1;//和为0的有一个子数组 空集
        int sum=0,res=0;//当前连续和  和为k的数组个数
        //k=sum-(sum-k) sum记录从0开始连续和 dict记录子数组和
        //如子数组sum(2,3)=sum(0,3)-sum(0,1)
        for(auto p:nums)
        {
            sum+=p;//到第i个数组元素的连续和
            //当前连续和为sum 若数组中有子数组和为sum-k
            //那么就有sum-(sum-k)=k,所以统计个数即可
            if(dict.count(sum-k)!=0)
                res+=dict[sum-k];
            dict[sum]++;//当前连续和为sum的
        }
        return res;
    }
};
