class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;//预判断
        //使用一个滑动窗口，保存不重复的字符，当出现字符时，删除其在滑动窗口中的位置及之前的所以字符
        int res=0;
        int size=s.size();
        string temp;
        for(int i=0;i<size;i++)
        {
            int index=isUnique(temp,s[i]);
            if(index==-1)//互异字符串中不含当前字符 将当前字符加入互异字符串
            {
                temp+=s[i];
            }
            else
            {
                temp=temp.substr(index+1,size);//将互异字符串中与当前字符相同的字符及之前的所以字符删除
                temp+=s[i];//互异字符串添加当前字符
            }
            res=max(res,int(temp.size()));//保存互异字符串的最大长度
        }
        return res;
    }
    int isUnique(string s,char c)//当前字符串中是否含c字符
    {
        int size=s.size();
        for(int i=0;i<size;i++)
        {
            if(c==s[i])
                return i;
        }
        return -1;
    }
};
