/*
题目：输入一个字符串，将其转换为INT型整数，实现atoi()功能。
返回字符串中第一个可读数字。如果第一个数字或正负号前面不是空格，那么返回0。第一个可读数字的结尾为字符串末尾或任意非数字字符。超过INT的数字，
输出INT_MAX(正数)，INT_MIN(负数)。
Example 1:
Input: "42"
Output: 42

Example 2:
Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.
Example 3:

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
Example 4:

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.
Example 5:

Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−231) is returned.
*/


class Solution {
public:
    int myAtoi(string str) {
        str=getDecStr(str);//获取第一个可读数字串
        int size=str.size();
        long res=0;
        bool exc=false;//记录数字串的数字是否超INT范围
        if(str[0]=='+')//首字符为'+'
        {
            for(int i=1;i<size;i++)
            {
                res*=10;//前几位的值*10进位
                res+=str[i]-'0';//加当前位数字
                if(res>INT_MAX)//超范围退出
                {
                    exc=true;
                    break;
                }
            }
            if(exc)
                return INT_MAX;
            else
                return res;
        }
        else if(str[0]=='-')//首字符为'-'
        {
            for(int i=1;i<size;i++)
            {
                res*=10;
                res+=str[i]-'0';
                if(res>INT_MAX)
                {
                    exc=true;
                    break;
                }
            }
            if(exc)
                return INT_MIN;
            else
                return -1*res;
        }
        else//首字符为数字
        {
            for(int i=0;i<size;i++)
            {
                res*=10;
                res+=str[i]-'0';
                if(res>INT_MAX)
                {
                    exc=true;
                    break;
                }
            }
            if(exc)
                return INT_MAX;
            else
                return res;
        }
    }
    string getDecStr(string str)//获取第一个可读数字串
    {
	    int size = str.size();
	    string res;
	    for (int i = 0; i < size; i++)
	    {
		    if (str[i] == ' ')//空格不处理 向后寻找
			    continue;
		    else if (str[i] == '+' || str[i] == '-')//第一个可读数字串的首字符为'+''-'
		    {
			    res += str[i];
			    for (int j = i + 1; j < size; j++)
			    {
				    if (!(str[j] - '0' >= 0 && str[j] - '0' <= 9))
					    break;
				    res += str[j];
			    }
			    break;
		    }
		    else if (str[i] - '0' >= 0 && str[i] - '0' <= 9)//第一个可读数字串的首字符为数字
		    {
			    for (int j = i; j < size; j++)
			    {
				    if (!(str[j] - '0' >= 0 && str[j] - '0' <= 9))
					    break;
				    res += str[j];
			    }
			    break;
		    }
		    else
			    break;
	    }
	    return res;
    }
};
