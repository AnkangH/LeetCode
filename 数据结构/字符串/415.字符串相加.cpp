/*
题目：
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.
Note:
The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
解析：
 num(char)->num(int)  -'0'
 反之+'0'
 利用两个string从最后一位（各位）开始加，需要判断两个string的位数，因为当位数低的到达最高位后，
 只使用另一个做加法。
 利用一个stack保存从位数从低到高的数字，再利用stack先进后出的特性，反向输出从最高位到最低位。
 注意十进制加法的进位关系，(a+b)%10留在当前位,(a+b)/10进位，可利用一个进位标志c。
*/
class Solution {
public:
    string addStrings(string a, string b) {
    stack<int> res;
	string result;
	int c = 0;
	int temp=0;
	int sizea = a.size()-1;
	int sizeb = b.size()-1;//
	if (sizea <= sizeb)
	    {
		    while (sizeb > -1)//加到string[0]为止，所以终止条件为大数组的索引到0
		    {
			    if (sizea > -1)//小数组索引未到0
			    {
				    temp = a[sizea] - '0' + b[sizeb] - '0' + c;
				    sizea--;//只有当小数组的索引不到0时，索引才-1左移
			    }
			    else
				    temp = b[sizeb] - '0' + c;
			    res.push(temp % 10);//保存当前位数字
			    c = temp / 10;//保存进位符
			    sizeb--;
		    }
		if (c == 1)
			res.push(1);//若两个数组大小相同，且最高位相加进位时，需要增加一位，又十进制
                        //进位，要么进1要么不进，所以push(1)即可,或push(c)
		while (!res.empty())
		{
			result.push_back(res.top()+'0');//根据栈的先入后出，将数字从低到高恢复到从高到低
			res.pop();
		}
	}
	else//数组大小不同时情况，只是数组交替
	{
		while (sizea > -1)
		{
			if (sizeb > -1)
			{
				temp = a[sizea] - '0' + b[sizeb] - '0' + c;
				sizeb--;
			}
			else
				temp = a[sizea] - '0' + c;
			res.push(temp % 10);
			c = temp / 10;
			sizea--;
		}
		if (c == 1)
			res.push(1);
		while (!res.empty())
		{
			result.push_back(res.top()+'0');
			res.pop();
		}
	}
	return result;
    }
};

//  2019/06/21更新
class Solution {
public:
    string addStrings(string num1, string num2) {
        int size1=num1.size();//num1位数
        int size2=num2.size();//num2位数
        string res;
        int size=0;//最大位数
        //对齐num1与num2的最低位 不够的前面补'0'
        if(size1<size2)
        {
            res=num2;
            size=size2;
            for(int i=size1;i<size2;i++)
                num1.insert(num1.begin(),'0');
        }
        else
        {
            res=num1;
            size=size1;
            for(int i=size2;i<size;i++)
                num2.insert(num2.begin(),'0');
        }
        int cof=0;//进位标志
        for(int i=size-1;i>=0;i--)//从低位开始计算
        {
            int temp=num1[i]-'0'+num2[i]-'0';//当前位的和
            temp+=cof;//加进位
            res[i]=temp%10+'0';//当前位的值
            cof=temp/10;//更新进位
        }
        if(cof!=0)
            res.insert(res.begin(),cof+'0');//若进位不为0 前面补一位
        return res;
    }
};
