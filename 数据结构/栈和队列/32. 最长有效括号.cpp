/*
给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
示例 1:
输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"
示例 2:
输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int longestValidParentheses(string& s) {
        int size=s.size();
        if(size==0||size==1)
            return 0;//空字符串或者单字符串一定不匹配
        stack<pair<int,char>> st;//辅助栈 既要记录字符也要记录字符的索引
        for(int i=0;i<size;i++)//遍历字符串每个字符
        {
            if(s[i]=='(')//左括号入栈
                st.push(pair<int,char>{i,'('});
            if(s[i]==')'&&!st.empty())//右括号判断是否合法
            {
                auto p=st.top();
                if(p.second=='(')//合法
                {
                    s[i]='*';//将匹配的'('和')'改为其他字符
                    s[p.first]='*';
                    st.pop();//出栈
                }
            }
        }
        int cnt=0,res=0;
        for(int i=0;i<size;i++)//遍历判断括号匹配后的字符串
        {
            if(s[i]=='*')//'*'意味着括号匹配
                cnt++;//记录当前连续匹配（即子串）的数目
            if(s[i]!='*'||i==size-1)//遇到不匹配或者遍历到字符串尾
            {
                res=max(res,cnt);//记录当前最大匹配子串中的括号数目
                cnt=0;//计数归零 为下次统计做准备
            }
        }
        return res;
    }
};
