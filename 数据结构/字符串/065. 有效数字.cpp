/*
验证给定的字符串是否可以解释为十进制数字。
例如:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false

说明: 我们有意将问题陈述地比较模糊。在实现代码之前，你应当事先思考所有可能的情况。这里给出一份可能存在于有效十进制数字中的字符列表：
数字 0-9
指数 - "e"
正/负号 - "+"/"-"
小数点 - "."
当然，在输入中，这些字符的上下文也很重要。
*/


class Solution {
public:
    bool isNumber(string s) {
        s=trim(s);//删除首尾的空格
        bool pointSeen = false;//当前已有小数点
        bool eSeen = false;//当前已有e
        bool numberSeen = false;//当前已有数字
        bool numberAfterE = true;//是否需要在数字后有e
        for(int i=0; i<s.length(); i++) 
        {
            if('0' <= s[i] && s[i] <= '9')//数字
            {
                numberSeen = true;//已有数字
                numberAfterE = true;//数字之后有e
            } 
            else if(s[i] == '.')//小数点
            {
                if(eSeen || pointSeen)
                    return false;//小数点前有e或者小数点 非法
                pointSeen = true;//已有小数点
            } 
            else if(s[i] == 'e')// e
            {
                if(eSeen || !numberSeen) 
                    return false;//已有e或者前面没有数字 非法
                numberAfterE = false;//e之后不需要数字
                eSeen = true;//已有e
            } 
            else if(s[i] == '-' || s[i] == '+')//正负
            {
                if(i != 0 && s[i-1] != 'e')//不是首字母且前面不是e
                    return false;//非法
            } 
            else
                return false;//不是数字 e 正负 小数点 均为非法
        }
        return numberSeen && numberAfterE;//剩余的有数字有e
    }
    string trim(string s)
    {
        auto itr=s.begin();//删除开始的空格
        while(*itr==' ')
            itr=s.erase(itr);
        if(s.empty())
            return s;//为空返回空
        itr=s.end();//删除后面的空格
        itr--;
        while(*itr==' ')
            itr=s.erase(itr)-1;
        return s;
    }
};
