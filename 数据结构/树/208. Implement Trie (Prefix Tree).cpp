class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root=new TrieNode('*');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if (word.empty())
		return;
	    TrieNode* cur = root;
	    int sizeWord = word.size();
	    for (int i=0;i<sizeWord;i++)
	    {
		    if (cur->next[word[i] - 'a'] != nullptr)
		    {
			    cur = cur->next[word[i] - 'a'];
			    if (i == sizeWord - 1)
				    cur->end = true;
		    }
		    else
		    {
			    cur->next[word[i] - 'a'] = new TrieNode(word[i]);
			    cur = cur->next[word[i] - 'a'];
			    if (i == sizeWord - 1)
				    cur->end = true;
		    }
	    }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (word.empty())
		    return false;
	    int sizeWord = word.size();
	    TrieNode* cur = root;
	    bool res;
	    for (int i=0;i<sizeWord;i++)
	    {
		    if (cur->next[word[i] - 'a'] != nullptr)
		    {
			    if (cur->next[word[i] - 'a']->val != word[i])
				    return false;
			    else
			    {
				    cur = cur->next[word[i] - 'a'];
				    if (i == sizeWord - 1)
					    res = cur->end;
			    }
		    }
		    else
			    return false;
	    }
	    return res;    
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if (prefix.empty())
	        return false;
	    int sizePrefix = prefix.size();
	    TrieNode* cur = root;
	    bool res;
	    for (int i = 0; i < sizePrefix; i++)
	    {
		    if (cur->next[prefix[i] - 'a'] != nullptr)
		    {
			    if (cur->next[prefix[i] - 'a']->val != prefix[i])
				    return false;
			    else
			    {
				    cur = cur->next[prefix[i] - 'a'];
				    if (i == sizePrefix-1)
					    res = true;
			    }
		}
		    else
			    return false;
	    }
	    return res; 
    }
private:
    struct TrieNode
    {
        char val;
        bool end;
        TrieNode* next[26];
        TrieNode(char c)
        {
            val=c;
            end=false;
            for(int i=0;i<26;i++)
                next[i]=nullptr;
        }
    };
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
