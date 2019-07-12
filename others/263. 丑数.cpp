/*
编写一个程序判断给定的数是否为丑数。
丑数就是只包含质因数 2, 3, 5 的正整数。
示例 1:
输入: 6
输出: true
解释: 6 = 2 × 3
示例 2:
输入: 8
输出: true
解释: 8 = 2 × 2 × 2
示例 3:
输入: 14
输出: false 
解释: 14 不是丑数，因为它包含了另外一个质因数 7。
说明：
1 是丑数。
输入不会超过 32 位有符号整数的范围: [−231,  231 − 1]。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ugly-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    bool isUgly(int num) {
        if(num<=0)
            return false;//非正数都不是丑书
        while(num>1)
        {
            if(num%2==0)
                num/=2;//能整除2就除以2
            else if(num%3==0)
                num/=3;//能整除3就除以3
            else if(num%5==0)
                num/=5;//能整除5就除以5
            else
                return false;//都不能整除说明不是丑数
        }
        return true;//否则num会除到1 是丑数
    }
};
