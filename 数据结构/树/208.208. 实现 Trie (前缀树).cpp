/*
实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。
示例:
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // 返回 true
trie.search("app");     // 返回 false
trie.startsWith("app"); // 返回 true
trie.insert("app");   
trie.search("app");     // 返回 true
说明:
你可以假设所有的输入都是由小写字母 a-z 构成的。
保证所有输入均为非空字符串。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-trie-prefix-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Trie {
public:
    struct TrieNode
    {
        char val;//当前节点的字符
        bool end;//标记当前节点是否为单词的结尾
        TrieNode* next[26];//26个小写字母构成当前节点的下一层节点
        TrieNode(char c){
            val=c;
            end=false;//初始化为false
            for(int i=0;i<26;i++)
                next[i]=nullptr;//初始化为nullptr
        };
    };
    TrieNode* head=new TrieNode('*');
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto p=head;
        int size=word.size();
        for(int i=0;i<size;i++)
        {
            if(p->next[word[i]-'a']==nullptr)//若节点为空
                p->next[word[i]-'a']=new TrieNode(word[i]);//增加新节点
            if(i==size-1)//最后一个字母对应节点
                p->next[word[i]-'a']->end=true;//标记是单词结尾
            p=p->next[word[i]-'a'];//节点下移 
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if(word.empty())
            return false;//预处理 空字符串返回
        int size=word.size();
        auto p=head;//使用头节点的副本进行查询
        for(int i=0;i<size;i++)
        {
            if(p->next[word[i]-'a']==nullptr||p->next[word[i]-'a']->val!=word[i])//当前节点为空 或字符与单词当前位不同
                return false;//返回false
            if(i==size-1&&p->next[word[i]-'a']->end!=true)
                return false;//查询到单词最后一个字母对应节点 判断是否为结尾
            p=p->next[word[i]-'a'];//节点下移
        }
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if(prefix.empty())
            return false;
        int size=prefix.size();
        auto p=head;
        for(int i=0;i<size;i++)
        {
            if(p->next[prefix[i]-'a']==nullptr||p->next[prefix[i]-'a']->val!=prefix[i])
                return false;//与查询单词类似 但是因为是前缀 所以不需结尾标记
            p=p->next[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

