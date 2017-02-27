/*
����������
��n���γ�0��1��2������n-1��
��pairl���͵����飬Ҫ����second������first;
�жϿγ��ܷ�����

For example:
2, [[1,0]]
�����ſΣ�����0������1����������

2, [[1,0],[0,1]]
�γɻ�·���޷�����

���������
�뷨��������֤�Ƿ���������
1�������Ϊ0�Ľڵ���ջ��
2����ջһ���ڵ�a����aָ��Ľڵ���ȼ�1��
3���ض�1��2��ֱ�����еĽڵ㶼����ջ�ͳ�ջ����Ϊ��������
*/


class Solution {
public:
	//�뷨��������֤�Ƿ���������
	//1�������Ϊ0�Ľڵ���ջ��
	//2����ջһ���ڵ�a����aָ��Ľڵ���ȼ�1��
	//3���ض�1��2��ֱ�����еĽڵ㶼����ջ�ͳ�ջ����Ϊ��������
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		if (prerequisites.empty())
			return true;
		vector<int> indegree(numCourses, 0);     //���ڵ����
		vector<bool> accessable(numCourses, 0);  //���ڵ�ɵ�
		map<int, vector<int>> adjvex;            //�����ӱ�
		for (const auto &c : prerequisites)
		{
			indegree[c.first]++;                    //����ڵ����
			adjvex[c.second].push_back(c.first);    //�������ӱ�    
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
				source_node.push(i);    //�����Ϊ0�ĵ���ջ
				accessable[i] = 1;        //��ʾ�ýڵ��ѵ�
			}//if
		}//for
	}
};