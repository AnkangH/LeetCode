/*
给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。
示例:
输入: 38
输出: 2 
解释: 各位相加的过程为：3 + 8 = 11, 1 + 1 = 2。 由于 2 是一位数，所以返回 2。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-digits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    int addDigits(int num) {
        while(num/10>0)//循环结束条件 一位数
        {
            int temp=0;//当前轮的更新值
            while(num>0)//取每一位
            {
                temp+=num%10;//当前位之和
                num/=10;//下一位
            }
            num=temp;//更新
        }
        return num;//最后的个位数
    }
};
