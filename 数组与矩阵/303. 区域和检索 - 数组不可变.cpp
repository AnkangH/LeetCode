/*
给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。
示例：
给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()
sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
说明:
你可以假设数组不可变。
会多次调用 sumRange 方法。
*/


class NumArray {
public:
    vector<int> sums;//保存sum(0,i) 0<=i<n
    NumArray(vector<int>& nums) {
        int sum=0;//当前和
        for(auto p:nums)//遍历数组
        {
            sum+=p;//加当前值
            sums.push_back(sum);//放入求和数组
        }
    }
    
    int sumRange(int i, int j) {
        if(i==0)
            return sums[j];//从0开始的和 返回sums
        else
            return sums[j]-sums[i-1];//否则是两个和之差
    }
};
