/*
序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，
采取相反方式重构得到原数据。
请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将
这个字符串反序列化为原始的树结构。
示例: 
你可以将以下二叉树：

    1
   / \
  2   3
     / \
    4   5

序列化为 "[1,2,3,null,null,4,5]"
提示: 这与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

说明: 不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string res;
        while(!q.empty())//层序遍历
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* t=q.front();
                q.pop();
                if(t!=nullptr)
                    res+=to_string(t->val);//非空节点放入字符串形式的值
                else
                    res+="null";//空节点放入null
                res+=',';
                if(t!=nullptr)//空节点无子节点 不放入
                {
                    q.push(t->left);
                    q.push(t->right);
                }
            }
        }
        res.pop_back();//删除最后的','
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> str;//分割字符串为null和数值
        string temp;
        for(auto p:data)
        {
            if(p!=',')
                temp+=p;
            else
            {
                str.push_back(temp);
                temp.clear();
            }
        }
        str.push_back(temp);
        if(str[0]=="null")
            return nullptr;//根节点为nullptr 返回nullptr
        TreeNode* res=new TreeNode(atoi(str[0].c_str()));//构建根节点
        queue<TreeNode*> q;//辅助队列 层序变量
        q.push(res);//根节点入队列
        int i=1;//标记当前节点下两个节点
        while(!q.empty())
        {
            TreeNode* t=q.front();//当前节点
            q.pop();//出队列
            if(str[i]=="null")
                t->left=nullptr;//左节点为空
            else
                t->left=new TreeNode(atoi(str[i].c_str()));//左节点非空
            i++;//子节点索引后移
            if(str[i]=="null")
                t->right=nullptr;//右节点为空
            else
                t->right=new TreeNode(atoi(str[i].c_str()));//右节点非空
            i++;//子节点索引后移
            if(t->left!=nullptr)
                q.push(t->left);//非空节点放入队列 继续构造二叉树
            if(t->right!=nullptr)
                q.push(t->right);
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
