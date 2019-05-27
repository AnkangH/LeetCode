#include<iostream>	//for cout endl
#include<vector>	//for vector
#include<queue>		//for queue
using namespace std;
struct Vertex
{
	vector<pair<int, int>> ad;//当前节点的邻接表
	bool known;//标记访问
	int dis;//起点到当前节点的最小距离
};
int main()
{
	//构建有向赋权图
	int vertexSize = 8;
	auto graph=new Vertex[vertexSize];
	graph[1].ad = { {2,2},{4,1} };
	graph[2].ad = { { 4,3 },{ 5,10 } };
	graph[3].ad = { { 1,4 },{ 6,5 } };
	graph[4].ad = { {3,2},{6,8},{7,4},{5,2} };
	graph[5].ad = { {7,6} };
	graph[6].ad = {};
	graph[7].ad = { {6,1} };
	for (int i = 2; i < vertexSize; i++)
	{
		graph[i].known = false;
		graph[i].dis = INT_MAX;
	}
	graph[1].dis = 0;
	//BFS
	queue<int>q;
	q.push(1);
	graph[1].known = true;
	while (!q.empty())
	{
		int cur = q.front();//当前节点
		q.pop();
		auto p=graph[cur].ad;//当前节点的邻接节点
		int size = p.size();
		//当前节点的所有未访问邻接节点更新
		for (int i = 0; i < size; i++)
			if (!graph[p[i].first].known)//遍历邻接节点
				graph[p[i].first].dis = min(graph[p[i].first].dis, graph[cur].dis + p[i].second);
				//取最小值	 		     上个邻接节点修改后的距离    当前节点修改后的距离
		//打印结果
		cout << "Vertex " << cur << "is known, dis[1]-dis[7]=" << endl;
		for (int i = 1; i < vertexSize; i++)
			cout << graph[i].dis << " ";
		cout << endl;
		//以未访问的节点中，最小距离最小的节点为下一个节点
		int minIndex = INT_MAX;
		int minVal = INT_MAX;
		for (int i = 1; i < vertexSize; i++)//遍历图节点
			if (graph[i].known == false)//若节点未访问
			{
				if (minIndex == INT_MAX)//首次赋值
				{
					minIndex = i;
					minVal = graph[i].dis;
				}
				else//取最小值，保存其对应索引
				{
					if (graph[i].dis < minVal)
					{
						minVal = graph[i].dis;
						minIndex = i;
					}
				}
			}
		//若存在未访问最小节点 则入队列，标记已读
		if (minIndex != INT_MAX)
		{
			q.push(minIndex);
			graph[minIndex].known = true;
		}
	}
}
