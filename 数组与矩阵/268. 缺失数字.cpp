/*
给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。
示例 1:
输入: [3,0,1]
输出: 2
示例 2:
输入: [9,6,4,2,3,5,7,0,1]
输出: 8
说明:
你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?
*/


//方法1 哈希表 时间O(n) 空间O(n)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        vector<bool> exists(n+1,false);//哈希表 记录出现的数字
        for(int i=0;i<n;i++)
            exists[nums[i]]=true;//记录
        for(int i=0;i<=n;i++)
            if(exists[i]==false)
                return i;//没有出现
        return -1;
    }
};


//方法2 高斯求和公式
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto p:nums)
            sum+=p;
        //一共有n+1个数字 但最大为n 所以和为1+2+...+n
        int sumReal=n*(n+1)/2;
        return sumReal-sum;
    }
};
