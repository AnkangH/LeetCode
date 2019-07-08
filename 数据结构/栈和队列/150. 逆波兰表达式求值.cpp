/*
根据逆波兰表示法，求表达式的值。
有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
说明：
整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
示例 1：
输入: ["2", "1", "+", "3", "*"]
输出: 9
解释: ((2 + 1) * 3) = 9
示例 2：
输入: ["4", "13", "5", "/", "+"]
输出: 6
解释: (4 + (13 / 5)) = 6
示例 3：
输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
输出: 22
解释: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/evaluate-reverse-polish-notation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.empty())
            return 0;
        stack<int> s;
        for(auto p:tokens)
        {
            int size=p.size();
            if(size!=1||(size==1&&p[0]-'0'>=0&&p[0]-'0'<=9))//一位数字或多位数字
                s.push(str2int(p));//数值入栈
            else if(p[0]=='+')//加法操作
            {
                int a=s.top();//栈顶数值
                s.pop();
                int b=s.top();//次栈顶数值
                s.pop();
                s.push(a+b);//和入栈
            }
            else if(p[0]=='-')//减法操作
            {
                int a=s.top();//栈顶元素
                s.pop();
                int b=s.top();//次栈顶元素
                s.pop();
                s.push(b-a);//差入栈
            }
            else if(p[0]=='*')//乘法操作
            {
                int a=s.top();//栈顶元素
                s.pop();
                int b=s.top();//次栈顶元素
                s.pop();
                s.push(a*b);//积入栈
            }
            else//除法操作
            {
                int a=s.top();//栈顶元素
                s.pop();
                int b=s.top();//次栈顶元素
                s.pop();
                s.push(b/a);//商入栈
            }
        }
        return s.top();//返回最终结果
    }
    int str2int(string s)//字符串转int
    {
        int res=0;
        int size=s.size();
        if(s[0]=='+')//首位为'+'
        {
            for(int i=1;i<size;i++)
            {
                res*=10;
                res+=s[i]-'0';
            }
            return res;
        }
        else if(s[0]=='-')//首位为'-'
        {
            for(int i=1;i<size;i++)
            {
                res*=10;
                res+=s[i]-'0';
            }
            return res*-1; 
        }
        else//首位为数字
        {
            for(int i=0;i<size;i++)
            {
                res*=10;
                res+=s[i]-'0';
            }
        }
        return res;
    }
};
