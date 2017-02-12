/*
问题描述：
将二叉树的每一层节点用链表连接起来

For example,
Given the following perfect binary tree,
1
/  \
2    3
/ \  / \
4  5  6  7
After calling your function, the tree should look like:
1 -> NULL
/  \
2 -> 3 -> NULL
/ \  / \
4->5->6->7 -> NULL

解决方法：
采用广度优先搜索算法，每一层元素使用deque存储
*/


/**
* Definition for binary tree with next pointer.
* struct TreeLinkNode {
*  int val;
*  TreeLinkNode *left, *right, *next;
*  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
* };
*/
class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (!root)   return;
		deque<TreeLinkNode*> que_link;
		que_link.push_back(root);
		root->next = NULL;
		while (!que_link.empty())
		{
			deque<TreeLinkNode*> tmp;       //采用deque来保存每一层的节点，广度优先搜索算法        
			for (auto &c : que_link)
			{
				if (c->left) tmp.push_back(c->left);
				if (c->right) tmp.push_back(c->right);
			}
			que_link = tmp;
			if (!que_link.empty())
			{
				for (auto itr = que_link.begin(); (itr + 1) != que_link.end(); itr++)
					(*itr)->next = *(itr + 1);
				auto last = que_link.back();
				last->next = NULL;
			}
		}
	}
};