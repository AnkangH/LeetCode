/*
实现一个基本的计算器来计算一个简单的字符串表达式的值。
字符串表达式仅包含非负整数，+， - ，*，/ 四种运算符和空格  。 整数除法仅保留整数部分。
示例 1:
输入: "3+2*2"
输出: 7
示例 2:
输入: " 3/2 "
输出: 1
示例 3:
输入: " 3+5 / 2 "
输出: 5
说明：
你可以假设所给定的表达式都是有效的。
请不要使用内置的库函数 eval。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/basic-calculator-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    int calculate(string s) {
        vector<string> str=str2str(s);//分割
        str=pre2back(str);//中缀转后缀
        return back2int(str);//计算后缀
    }
    bool priority(string a,string b)//a优先级大于b返回true 
    {
        if(a=="+"||a=="-")
        {
            if(b=="+"||b=="-")//加减优先级比加减高 
                return true;
            else
                return false;//加减等优先级 不比乘除高
        }
        else
            return true;//乘除的优先级比其他都高
    }
    vector<string> str2str(string s)//分割字符串
    {
        vector<string> res;
        string temp;
        for(auto p:s)
        {
            if(p==' ')
                continue;//跳过空格
            else if(p!='+'&&p!='-'&&p!='*'&&p!='/')
                temp+=p;//数字直接放入暂存
            else
            {
                if(!temp.empty())
                    res.push_back(temp);//上一个放入结果
                temp.clear();
                res.push_back(temp+p);//当前放入结果
                temp.clear();
            }
        }
        if(!temp.empty())
            res.push_back(temp);//最后的一个暂存
        return res;
    }
    vector<string> pre2back(vector<string> s)//中缀表达式转后缀表达式
    {
        vector<string> res;
        stack<string> st;
        for(auto p:s)
        {
            if(p!="+"&&p!="-"&&p!="*"&&p!="/")
                res.push_back(p);//数字直接放入表达式
            else//运算符
            {
                if(st.empty())
                    st.push(p);//栈空入栈
                else
                {
                    while(priority(st.top(),p))//栈顶元素优先级大于当前
                    {
                        res.push_back(st.top());//栈顶放入表达式
                        st.pop();//出栈
                        if(st.empty())
                            break;//判断栈空
                    }
                    st.push(p);//直到栈空 或栈中优先级不比当前大 把当前运算符放入栈中
                }
            }
        }
        while(!st.empty())//栈中剩余运算符取出
        {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
    int back2int(vector<string> s)//计算后缀表达式的值
    {
        stack<int> st;
        for(auto p:s)
        {
            if(p=="+")//加法
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(a+b);
            }
            else if(p=="-")//减法
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(b-a);
            }
            else if(p=="*")//乘法
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(a*b);
            }
            else if(p=="/")//除法
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(b/a);
            }
            else
                st.push(atoi(p.c_str()));//数字入栈
        }
        return st.top();//计算结果
    }
};
