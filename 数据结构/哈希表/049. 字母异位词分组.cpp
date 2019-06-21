/*
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
示例:
输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：
所有输入均为小写字母。
不考虑答案输出的顺序。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/group-anagrams
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if(strs.empty())
            return res;
        unordered_map<string,vector<string>> m;//哈希表 用于储存相同组合的字符串
        int size=strs.size();
        for(int i=0;i<size;i++)//遍历数组
        {
            string cur=strs[i];//当前字符串
            sort(cur.begin(),cur.end());//获取ASCII排序后的字符串 组合相同的字符串 必有相同的排序
            m[cur].push_back(strs[i]);//检索排序后的字符串 若存在 则放入 若不存在 则建立新的key并放入
        }
        for(auto p:m)
            res.push_back(p.second);//顺序取出每个key值对应的字符串组合即可
        return res;
    }
};
