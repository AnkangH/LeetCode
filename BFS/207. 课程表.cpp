/*
现在你总共有 n 门课需要选，记为 0 到 n-1。
在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]
给定课程总量以及它们的先决条件，判断是否可能完成所有课程的学习？
示例 1:
输入: 2, [[1,0]] 
输出: true
解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。
示例 2:
输入: 2, [[1,0],[0,1]]
输出: false
解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0 之前，你还应先完成课程 1。这是不可能的。
说明:
输入的先决条件是由边缘列表表示的图形，而不是邻接矩阵。详情请参见图的表示法。
你可以假定输入的先决条件中没有重复的边。
提示:
这个问题相当于查找一个循环是否存在于有向图中。如果存在循环，则不存在拓扑排序，因此不可能选取所有课程进行学习。
通过 DFS 进行拓扑排序 - 一个关于Coursera的精彩视频教程（21分钟），介绍拓扑排序的基本概念。
拓扑排序也可以通过 BFS 完成。
*/


//不使用自定义顶点结构
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> course(numCourses);
        for(int i=0;i<numCourses;i++)
            course[i]=i;//课程序号
        vector<vector<int>> ad(numCourses);//邻接表 先修课程到后修课程
        vector<int> inLines(numCourses,0);//每个课程的入度
        vector<bool> known(numCourses,false);//该课程是否已拓扑排序
        for(auto p:prerequisites)
        {
            ad[p[1]].push_back(p[0]);//a b代表b->a的边
            inLines[p[0]]++;//a的入度+1
        }
        queue<int> q;//辅助队列
        for(int i=0;i<numCourses;i++)
        {
            if(inLines[i]==0)
            {
                q.push(i);//入度为0的课程入队列
                known[i]=true;//标记已有序
            }
        }
        while(!q.empty())//继续拓扑排序
        {
            int cur=q.front();//当前课程
            q.pop();
            auto p=ad[cur];//后修课程
            for(auto pp:p)//遍历每个后修课程
            {
                inLines[pp]--;//删除该边 即后修课程的入度-1 因为当前节点唯一访问 所以不需要删除邻接表
                if(inLines[pp]==0&&known[pp]==false)//删除边后 该节点的入度为0且未在拓扑排序中
                {
                    q.push(pp);//入队列
                    known[pp]=true;//标记已有序
                }
            }
        }
        for(auto p:known)
            if(!p)
                return false;//某个课程无序 说明无法拓扑排序
        return true;//拓扑有序
    }
};


//使用自定义顶点结构体 入度 邻接表 是否已读都是顶点的属性
class Solution {
public:
    struct Vertex
    {
        //int index;//数组i代表顶点的序号 因此不需额外变量
        int inCnt=0;//顶点的入度
        bool known=false;//顶点在拓扑排序中是否已读
        vector<int> ad;//邻接表
    };
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<Vertex> course(numCourses);
        for(auto p:prerequisites)
        {
            course[p[1]].ad.push_back(p[0]);//邻接表
            course[p[0]].inCnt++;//入度+1
        }
        queue<int> q;//辅助队列 使用序号进行bfs即可
        for(int i=0;i<numCourses;i++)
        {
            if(course[i].inCnt==0)
            {
                q.push(i);//入度为0的顶点入队列
                course[i].known=true;//标记已读
            }
        }
        while(!q.empty())
        {
            int cur=q.front();//当前顶点
            q.pop();
            for(auto p:course[cur].ad)//邻接顶点
            {
                course[p].inCnt--;//邻接顶点的入度-1
                if(course[p].inCnt==0&&!course[p].known)//邻接顶点的入度为0且未访问
                {
                    q.push(p);//放入队列
                    course[p].known=true;//标记已读
                }
            }
        }
        for(auto p:course)
            if(!p.known)
                return false;//有未读顶点 说明无拓扑排序
        return true;//否则返回有序
    }
};
