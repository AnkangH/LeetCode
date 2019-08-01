/*
现在你总共有 n 门课需要选，记为 0 到 n-1。
在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]
给定课程总量以及它们的先决条件，返回你为了学完所有课程所安排的学习顺序。
可能会有多个正确的顺序，你只要返回一种就可以了。如果不可能完成所有课程，返回一个空数组。
示例 1:
输入: 2, [[1,0]] 
输出: [0,1]
解释: 总共有 2 门课程。要学习课程 1，你需要先完成课程 0。因此，正确的课程顺序为 [0,1] 。
示例 2:
输入: 4, [[1,0],[2,0],[3,1],[3,2]]
输出: [0,1,2,3] or [0,2,1,3]
解释: 总共有 4 门课程。要学习课程 3，你应该先完成课程 1 和课程 2。并且课程 1 和课程 2 都应该排在课程 0 之后。
     因此，一个正确的课程顺序是 [0,1,2,3] 。另一个正确的排序是 [0,2,1,3] 。
说明:
输入的先决条件是由边缘列表表示的图形，而不是邻接矩阵。详情请参见图的表示法。
你可以假定输入的先决条件中没有重复的边。
提示:
这个问题相当于查找一个循环是否存在于有向图中。如果存在循环，则不存在拓扑排序，因此不可能选取所有课程进行学习。
通过 DFS 进行拓扑排序 - 一个关于Coursera的精彩视频教程（21分钟），介绍拓扑排序的基本概念。
拓扑排序也可以通过 BFS 完成。
*/


class Solution {
public:
    struct Vertex
    {
        int inCnt=0;//顶点入度
        bool known=false;//是否已在拓扑排序中
        vector<int> ad;//邻接表
    };
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<Vertex> course(numCourses);//n个顶点
        for(auto p:prerequisites)
        {
            course[p[1]].ad.push_back(p[0]);// b->a 
            course[p[0]].inCnt++;//a的入度+1
        }
        queue<int> q;//辅助队列 顺序遍历
        for(int i=0;i<numCourses;i++)
            if(course[i].inCnt==0)//入度为0
            {
                q.push(i);//入队列
                course[i].known=true;//已在拓扑排序中
            }
        vector<int> res;//保存拓扑排序
        while(!q.empty())
        {
            int cur=q.front();//当前顶点
            q.pop();
            res.push_back(cur);//当前顶点放入拓扑排序中
            for(auto p:course[cur].ad)//遍历cur的邻接顶点nxt
            {
                course[p].inCnt--;//nxt的入度-1
                if(course[p].inCnt==0&&!course[p].known)//nxt的入度为0且未在拓扑排序中
                {
                    q.push(p);//放入队列
                    course[p].known=true;//已在拓扑排序中
                }
            }
        }
        if(res.size()==numCourses)
            return res;//有拓扑排序
        else
            return {};//无拓扑排序
    }
};
