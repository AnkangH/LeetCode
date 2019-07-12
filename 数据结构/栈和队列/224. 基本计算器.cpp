/*
实现一个基本的计算器来计算一个简单的字符串表达式的值。
字符串表达式可以包含左括号 ( ，右括号 )，加号 + ，减号 -，非负整数和空格  。
示例 1:
输入: "1 + 1"
输出: 2
示例 2:
输入: " 2-1 + 2 "
输出: 3
示例 3:
输入: "(1+(4+5+2)-3)+(6+8)"
输出: 23
说明：
你可以假设所给定的表达式都是有效的。
请不要使用内置的库函数 eval。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/basic-calculator
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


//标准解法 适用于+-*/
class Solution {
public:
    int calculate(string s) {
        vector<string> str;
        str=str2str(s);//分割
        str=pre2back(str);//后缀转前缀
        return back2int(str);//计算后缀
    }
    vector<string> str2str(string s)//切分输入的表达式为数字 左右括号 运算符
    {
        vector<string> res;
        string temp;
        for(auto p:s)
        {
            if(p==' ')
                continue;//跳过空格
            else if(p=='('||p==')'||p=='+'||p=='-')//遇到运算符进行切割
            {
                if(!temp.empty())
                    res.push_back(temp);//放入上个字符串
                temp.clear();
                temp+=p;
                res.push_back(temp);//放入当前字符串
                temp.clear();//准备继续更新
            }
            else
                temp+=p;//放入当前字符串
        }
        if(!temp.empty())
            res.push_back(temp);//最后temp非空 也要放入
        return res;
    }
    vector<string> pre2back(vector<string> s)
    {
        vector<string> res;
        stack<string> st;
        for(auto p:s)
        {
            
            if(p=="(")//左括号
                st.push(p);//入栈
            else if(p=="+"||p=="-")//运算符
            {
                if(st.empty())
                    st.push(p);//栈空入栈
                else
                {
                    string temp=st.top();//否则取出栈顶运算符
                    if(st.top()!="(")
                    {
                        st.pop();//出栈
                        res.push_back(temp);//放入后缀表达式
                        st.push(p);//当前运算符入栈
                    }
                    else
                        st.push(p);
                }
            }
            else if(p==")")//右括号
            {
                while(st.top()!="(")//一直出栈直到发现左括号
                {
                    res.push_back(st.top());
                    st.pop();
                }
                st.pop();//左括号出栈
            }
            else//数字放入后缀表达式
                res.push_back(p);
        }
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
    int back2int(vector<string> s)//计算后缀表达式
    {
        stack<int> st;
        for(auto p:s)//遍历表达式
        {
            if(p=="+")//如果是加法运算符
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(a+b);//取栈顶两元素做加法
            }
            else if(p=="-")//减法运算符
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(b-a);//取栈顶为被减数 次栈顶为减数做减法
            }
            else
                st.push(atoi(p.c_str()));//数字直接入栈
        }
        return st.top();//返回栈顶计算结果
    }
};



//不使用标准解法 
class Solution {
public:
    //bool has=false;
    int calculate(string s) {
        vector<string> str;
        str=str2str(s);//分割
        stack<string> st;//利用栈来解决括号
        for(auto p:str)
        {
            if(p!=")")
                st.push(p);//非右括号 直接入栈
            else//左括号
            {
                vector<string> temp;//保存一个没有括号的运算表达式
                while(st.top()!="(")//直到左括号
                {
                    temp.push_back(st.top());//当前放入表达式
                    st.pop();//出栈
                }
                st.pop();//左括号出栈
                reverse(temp.begin(),temp.end());//逆序
                st.push(to_string(com(temp)));//计算结果放入栈中
            }
        }
        vector<string> temp;//对栈中剩余没有括号的部分计算
        while(!st.empty())
        {
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(),temp.end());//逆序
        return com(temp);//计算
    }
    vector<string> str2str(string s)//切分输入的表达式为数字 左右括号 运算符
    {
        vector<string> res;
        string temp;
        for(auto p:s)
        {
            if(p==' ')
                continue;//跳过空格
            else if(p=='('||p==')'||p=='+'||p=='-')//遇到运算符进行切割
            {
                if(!temp.empty())
                    res.push_back(temp);//放入上个字符串
                temp.clear();
                temp+=p;
                res.push_back(temp);//放入当前字符串
                temp.clear();//准备继续更新
            }
            else
                temp+=p;//放入当前字符串
        }
        if(!temp.empty())
            res.push_back(temp);//最后temp非空 也要放入
        return res;
    }
    int com(vector<string> s)//计算一个没有括号的加法减法表达式
    {
        int res=0;
        int flag=1;
        for(auto p:s)
        {
            if(p!="+"&&p!="-")
                res+=flag*atoi(p.c_str());
            else if(p=="-")
                flag=-1;
            else
                flag=1;
                
        }
        return res;
    }
};
