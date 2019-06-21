/*
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
示例 1:
输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:
输入: num1 = "123", num2 = "456"
输出: "56088"
说明：
num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/multiply-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")
            return "0";
        int size=num2.size();
        string res=mul(num1,num2[size-1]);//num1与num2最低位的乘积
        for(int i=size-2;i>=0;i--)//从低位开始
        {
            string temp=mul(num1,num2[i]);//当前位乘积
            res=add(res,temp,size-i);//当前位乘积的值与上个乘积的倒数第k位对齐 k=2,3,...size-2
        }
        return res;
    }
    string mul(string num1,char c)//num1和num2[i]的乘积 整数*0-9的数字
    {
        int size=num1.size();
        string res=num1;
        int cof=0;//进位标志
        for(int i=size-1;i>=0;i--)//从低位开始
        {
            int temp=(num1[i]-'0')*(c-'0');//当前位乘积
            temp+=cof;//加进位
            res[i]=temp%10+'0';//更新当前位的值
            cof=temp/10;//更新进位
        }
        if(cof!=0)
            res.insert(res.begin(),cof+'0');//进位不为0 前面补一位 注意cof可以比1大
        return res;
    }
    string add(string& num1,string& num2,int i)//num2最后一位和num1的倒数第i位对齐
    {
        int size2=num2.size();
        int size1=num1.size();
        int size=size2+i-1;//总长度 num2.size()+i-1
        for(int i=size2;i<size;i++)
            num2.push_back('0');//num2高位 后面补0
        for(int i=size1;i<size;i++)
            num1.insert(num1.begin(),'0');//num1低位 前面补0
        int cof=0;//进位标志
        string res=num1;//等长度数字求和
        for(int i=size-1;i>=0;i--)//从后（低位开始）
        {
            int temp=(num1[i]-'0')+(num2[i]-'0');//当前位求和
            temp+=cof;//加进位值
            res[i]=temp%10+'0';//当前位的值
            cof=temp/10;//更新进位值
        }
        if(cof!=0)
            res.insert(res.begin(),cof+'0');//进位值不为0 在前面加一位1
        return res;
    }
};
