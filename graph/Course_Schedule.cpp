/*
问题描述：
给n个课程0，1，2，，，n-1；
给pairl类型的数组，要先修second，再修first;
判断课程能否修完

For example:
2, [[1,0]]
共两门课，先修0，再修1，可以修完

2, [[1,0],[0,1]]
形成回路，无法修完

解决方法：
想法：就是验证是否拓扑有序
1、将入度为0的节点入栈；
2、出栈一个节点a，将a指向的节点入度减1；
3、重读1、2，直至所有的节点都能入栈和出栈，则为拓扑有序
*/


class Solution {
public:
	//想法：就是验证是否拓扑有序
	//1、将入度为0的节点入栈；
	//2、出栈一个节点a，将a指向的节点入度减1；
	//3、重读1、2，直至所有的节点都能入栈和出栈，则为拓扑有序
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		if (prerequisites.empty())
			return true;
		vector<int> indegree(numCourses, 0);     //各节点入度
		vector<bool> accessable(numCourses, 0);  //各节点可到
		map<int, vector<int>> adjvex;            //邻链接表
		for (const auto &c : prerequisites)
		{
			indegree[c.first]++;                    //求个节点入度
			adjvex[c.second].push_back(c.first);    //求邻连接表    
		}
		stack<int> source_node;
		pushStack(numCourses, indegree, source_node, accessable);
		while (!source_node.empty())
		{
			int node = source_node.top();
			source_node.pop();
			for (auto &c : adjvex[node])
				indegree[c]--;
			pushStack(numCourses, indegree, source_node, accessable);
		}
		for (auto c : accessable)
		{
			if (!c)
				return false;
		}
		return true;
	}
	void pushStack(int &numCourses, vector<int> &indegree, stack<int> &source_node, vector<bool> &accessable)
	{
		for (int i = 0; i<numCourses; i++)
		{
			if (indegree[i] == 0 && accessable[i] == 0)
			{
				source_node.push(i);    //将入度为0的点入栈
				accessable[i] = 1;        //表示该节点已到
			}//if
		}//for
	}
};