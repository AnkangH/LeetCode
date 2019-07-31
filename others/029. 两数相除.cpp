/*
给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
返回被除数 dividend 除以除数 divisor 得到的商。
示例 1:
输入: dividend = 10, divisor = 3
输出: 3
示例 2:
输入: dividend = 7, divisor = -3
输出: -2
说明:
被除数和除数均为 32 位有符号整数。
除数不为 0。
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。
*/


class Solution {
public:
    int divide(int dividend, int divisor) {
        long a=dividend;
        long b=divisor;
        long cof=1;
        if(a<0&&b>0||a>0&&b<0)
            cof=-1;//符号位 异号为负
        if(a<0)
            a*=-1;//取绝对值
        if(b<0)
            b*=-1;//取绝对值
        long res=0;//商
        for(int i=31;i>=0;i--)//使用2的幂多项式*divisor来逼近dividend
        {
            if(a>=b*1l<<i)//1默认为int型 左移31位为INT_MIN 所以使用long 1
            {
                res+=1l<<i;//当前的系数 k1*b
                a-=b*1l<<i;//a=a-k1*b 对剩余数值进行使用多项式逼近
            }
        }
        if(res*cof>INT_MAX)
            return INT_MAX;
        else
            return res*cof;
    }
};
