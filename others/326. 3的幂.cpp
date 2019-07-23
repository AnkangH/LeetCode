/*
给定一个整数，写一个函数来判断它是否是 3 的幂次方。
示例 1:
输入: 0
输出: false
示例 3:

输入: 9
输出: true
示例 4:

输入: 45
输出: false
进阶：
你能不使用循环或者递归来完成本题吗？
*/


class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)
            return false;
        while(n>1)
        {
            if(n%3!=0)
                return false;//不能整除3 不是3的幂
            n/=3;
        }
        return true;//除以3一直到1 是3的幂
    }
};
