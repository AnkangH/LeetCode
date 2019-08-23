/*
字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。
示例 1:
输入: S = "ababcbacadefegdehijhklij"
输出: [9,7,8]
解释:
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
注意:
S的长度在[1, 500]之间。
S只包含小写字母'a'到'z'。
*/


class Solution {
public:
    vector<int> partitionLabels(string s) {
      vector<int> last(26,0);
      int n=s.size();
      for(int i=0;i<n;i++)
        last[s[i]-'a']=i;//每个字母最后出现的位置
      int start=0,end=0;
      vector<int> res;
     for(int i=0;i<n;i++)
     {
       end=max(end,last[s[i]-'a']);//前i个字母中 最后出现最远的那个位置
       if(i==end)//s(start,end)中任何一个字母都不在其后出现
       {
         res.push_back(end-start+1);//以当前start和end划分一个区间
         start=end+1;//起点移动
       }
     }
      return res;
    }
};
