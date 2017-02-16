/*
����������
��ͼ���и���


���������
1�������ǽ���ͼ�ĸ��ƣ�ԭ�ڵ�Ҫ���µĽڵ㽨��һһӳ���ϵ�����ǹ�ϣ
2���ѷ��ʹ��Ľڵ㲻���ظ����ʣ�����unordered_map
3������DFS��ʽ����ͼ
*/


/**
* Definition for undirected graph.
* struct UndirectedGraphNode {
*     int label;
*     vector<UndirectedGraphNode *> neighbors;
*     UndirectedGraphNode(int x) : label(x) {};
* };
*/
class Solution {
public:
	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash;
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (!node)   return node;
		if (hash.find(node) == hash.end())
		{
			hash[node] = new UndirectedGraphNode(node->label);
			for (const auto &c : node->neighbors)
				(hash[node]->neighbors).push_back(cloneGraph(c));
		}
		return hash[node];
	}
};