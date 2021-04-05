/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
示例 1:
输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/

//方法一 使用字符串做为滑动窗口
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

//方法二 使用哈希表作为滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
        unordered_map<char,int> m;//哈希表滑动窗口 储存字符及其在字符串中的位置
        m.emplace(s[0],0);//放入字符串首个字符
        int res=1;//放入首个字符后 初始长度为1
        int size=s.size();
        for(int i=1;i<size;i++)//遍历其后字符串每个字符
        {
            if(m.count(s[i])==0)//不在滑动窗口中
            {
                m.emplace(s[i],i);//放入滑动窗口
            }
            else
            {
                int index=m.find(s[i])->second;//找出滑动窗口中给字符在字符串中的位置
                auto p=m.begin();
                while(p!=m.end())//
                {
                    if(p->second<=index)//删除该字符及前面的字符
                        p=m.erase(p);
                    else
                        p++;
                }
                m.emplace(s[i],i);//放入当前字符
            }
            int sum=m.size();//统计滑动窗口中的字符个数
            res=max(res,sum);//保存最大长度
        }
        return res;
    }
};


//2021.4.5
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
            return 0;
        
        int left=0;
        int result = 1;
        // 记录每个子串中不重复字符串的长度
        set<char> exists;
        exists.insert(s[left]);
        for(int right=1;right<s.size();right++){
            //该字符串不重复 放入哈希表
            if(exists.find(s[right])==exists.end()){
                exists.insert(s[right]);
            }
            // 该字符重复 遍历子串 将重复字符之前的所有字符从哈希表中删除
            // 将子串中重负字符的下一个作为左指针的新起点
            else{
                while(left<right){
                    if(s[left]!=s[right]){
                        exists.erase(s[left]);
                    }
                    else{
                        left+=1;
                        break;
                    }
                    left+=1;
                }
            }
            //判断最大子串的长度 注意完全无重复的情况
            if(exists.size()>result){
                result=exists.size();
            }
        }
        return result;
    }
};

/*
注意erase的多态 根据传入参数类型不同 可删除指定值或者迭代器指向的对象
*/
