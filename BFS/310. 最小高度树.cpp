/*
对于一个具有树特征的无向图，我们可选择任何一个节点作为根。图因此可以成为树，在所有可能的树中，具有最小高度的树被称为最小高度树。
给出这样的一个图，写出一个函数找到所有的最小高度树并返回他们的根节点。
该图包含 n 个节点，标记为 0 到 n - 1。给定数字 n 和一个无向边 edges 列表（每一个边都是一对标签）。
你可以假设没有重复的边会出现在 edges 中。由于所有的边都是无向边， [0, 1]和 [1, 0] 是相同的，因此不会同时出现在 edges 里。
*/


//方法一 以每个顶点作为根节点 判断其生成树的高度 超时
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> res;//保存以每个节点为顶点的树的高度
        vector<vector<int>> ad(n);//保存每个顶点的邻接表
        for(auto p:edges)
        {
            ad[p[0]].push_back(p[1]);
            ad[p[1]].push_back(p[0]);//无向图
        }
        int minLayer=INT_MAX;//记录最小高度
        for(int i=0;i<n;i++)//处理每个节点作为根节点
        {
            queue<int> q;
            vector<bool> known(n,false);//记录每个节点是否访问过
            q.push(i);
            known[i]=true;
            int layer=0;//高度
            while(!q.empty())
            {
                int size=q.size();
                for(int j=0;j<size;j++)
                {
                    int cur=q.front();
                    q.pop();
                    for(auto p:ad[cur])
                    {
                        if(!known[p])
                        {
                            q.push(p);
                            known[p]=true;
                        }
                    }
                }
                layer++;
            }
            res.push_back(layer);//第i个节点作为根节点 生成树的高度
            minLayer=min(minLayer,layer);
        }
        vector<int> minIndex;
        for(int i=0;i<n;i++)
            if(res[i]==minLayer)
                minIndex.push_back(i);//将最小高度的顶点索引放入数组
        return minIndex;//返回
    }
};


//方法二 删除叶节点法
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1&&edges.empty())
            return {0};//只有一个节点 邻接表为空时 此时树的根节点为该节点
        vector<vector<int>> ad(n);//邻接表 
        for(auto p:edges)
        {
            ad[p[0]].push_back(p[1]);//0->1
            ad[p[1]].push_back(p[0]);//1->0
        }
        queue<int> q;//辅助队列 按照层序 从叶节点网上遍历
        int size=n;//全部节点个数
        for(int i=0;i<n;i++)
            if(ad[i].size()==1)
                q.push(i);//叶节点入队列
        while(size>2)//剩余1或2个节点时退出
        {
            int sizeLayer=q.size();//当前层的节点个数
            size-=sizeLayer;//剩余节点个数
            for(int i=0;i<sizeLayer;i++)//当前层每个节点
            {
                int cur=q.front();//当前节点
                q.pop();//出队列
                int nxt=ad[cur][0];//该叶节点连接的上一层节点nxt
                auto itr=ad[nxt].begin();//
                while(itr!=ad[nxt].end())//遍历nxt的邻接表 将nxt->cur的枝剪断
                {
                    if(*itr==cur)
                    {
                        ad[nxt].erase(itr);
                        break;
                    }
                    itr++;
                }
                if(ad[nxt].size()==1)//剪掉nxt->cur枝后 nxt只有一个枝
                    q.push(nxt);//说明nxt为叶节点 所以入队列
            }
        }
        vector<int> res;
        while(!q.empty())
        {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
