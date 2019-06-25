/*
实现 int sqrt(int x) 函数。
计算并返回 x 的平方根，其中 x 是非负整数。
由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
示例 1:
输入: 4
输出: 2
示例 2:
输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sqrtx
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    int mySqrt(int x) {
        if(x<=1)
            return x;//x=0,1时，r无效
        int l=1,r=x-1;
        while(l<=r)
        {
            int mid=(r-l)/2+l;
            int sqrt=x/mid;//使用商作为判断标准
            if(sqrt==mid)
                return mid;
            else if(sqrt<mid)
                r=mid-1;
            else
                l=mid+1;
            /*
            long mul=mid;//使用乘积作为判断标准 注意int型的乘积可能超范围
            mul*=mul;
            if(mul==x)
                return mid;
            else if(mul>x)
                r=mid-1;
            else
                l=mid+1;
            */
            
        }
        return r;//当r=l时，如果未退出那么肯定此时的乘积<x,下一步l=mid+1乘积会大于x 不满足 所以返回r 可使用数字验证
    }
};
