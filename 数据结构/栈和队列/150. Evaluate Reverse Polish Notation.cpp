/*
题目：
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, /. Each operand may be an integer or another expression.
Note:
Division between two integers should truncate toward zero.
The given RPN expression is always valid. That means the expression would always evaluate to a result and 
there won't be any divide by zero operation.
Example 1:
Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:
Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:
Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
解析：给定一个后缀表达式，求其计算结果。
后缀表达式的计算用栈来实现，较简单。分为两种情况，数字和运算符。
如果是数字，直接入栈。
如果是运算符，又分为两种情况，其中'+'和'*'为一种，对操作数的顺序无要求；'-'和'/'为一种，对操作数的顺序有要求。
如果是'+' '*'，那么取栈顶两元素（取栈顶，出栈，再取栈顶，再出栈），根据运算符计算结果后入栈。
如果是'-'和'/'，那么取栈顶元素为被减数（被除数），出栈，再取栈顶元素为减数（除数），执行对应运算，结果入栈。
遍历后缀表达式，根据每个元素的分类执行上述操作，最后取栈顶元素即为后缀表达式的运算结果。
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int size=tokens.size();
        stack<int> s;
        for(int i=0;i<size;i++)
        {
            if(tokens[i]=="+")
            {
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                int cur=a+b;
                s.push(cur);
            }
            else if(tokens[i]=="-")
            {
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                int cur=b-a;
                s.push(cur);
            }
            else if(tokens[i]=="*")
            {
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                int cur=a*b;
                s.push(cur);
            }
            else if(tokens[i]=="/")
            {
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                int cur=b/a;
                s.push(cur);
            }
            else
                s.push(str2int(tokens[i]));
        }
        return s.top();
    }
    int str2int(string str)
    {
        int res=0;
        int size=str.size();
        if(str[0]=='-')
        {
            for(int i=size-1;i>0;i--)
                res+=(str[i]-'0')*pow(10,size-1-i);
            return res*(-1);
        }
        else
        {
            for(int i=size-1;i>=0;i--)
                res+=(str[i]-'0')*pow(10,size-1-i);
            return res;
        }
    }
};
