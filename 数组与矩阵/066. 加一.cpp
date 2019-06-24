/*
给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。
你可以假设除了整数 0 之外，这个整数不会以零开头。
示例 1:
输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
示例 2:
输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/plus-one
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int cof=0;//进位值
        int add;//相加值
        int size=digits.size();
        for(int i=size-1;i>=0;i--)
        {
            if(i==size-1)
                add=1;//最低位加一次1
            else
                add=0;//其余均不加1
            int temp=digits[i]+add+cof;//当前和
            digits[i]=temp%10;//当前值
            cof=temp/10;//记录是否有进位
        }
        if(cof!=0)//最高位有进位
            digits.insert(digits.begin(),1);//前面加1
        return digits;
    }
};
