/*
问题描述：
对图进行复制


解决方法：
1、由于是进行图的复制，原节点要和新的节点建立一一映射关系，考虑哈希
2、已访问过的节点不能重复访问，采用unordered_map
3、采用DFS方式遍历图
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