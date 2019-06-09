/*
Given a 32-bit signed integer, reverse digits of an integer.
Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. 
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

class Solution {
public:
    int reverse(int x) 
    {
        int cof=1;
        long res=0;//对int操作时 结果可能超int范围
        long val=x;
        if(x<0)
        {
            val*=-1;//取绝对值
            cof=-1;//记录符号位
        }
        else
            val=x;
        while(val>0)
        {
            res*=10;//当前结果进一位
            res+=val%10;//加当前位
            val/=10;//数字去掉当前位
        }
        //若计算结果超过INT范围 返回0 否则返回结果
        return res>INT_MAX? 0:res*cof;
    }
};
