/*
问题描述：
二叉树的先序遍历

解决方法：
采用非递归的方式，采用堆栈的方式保存节点
先序遍历：先遍历左子树，输出根节点，再遍历右子树
采用堆栈，
1、将左子树一直入栈，
2、然后输出节点，输出的节点如果有右子树，入栈一个右子树
3、对于2的结果，重复1
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
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> node_val;
		if (!root)   return node_val;
		stack<TreeNode*> tree;
		tree.push(root);
		while (!tree.empty())
		{
			auto node = tree.top();
			//左子树持续入栈
			while (node->left)
			{
				tree.push(node->left);
				//注意这里，对于已入栈的节点(栈内未输出)，应该去除父子关系
				//否则，可能导致死循环
				auto tmp = node;
				node = node->left;
				tmp->left = NULL;
			}
			node = tree.top();
			//输出节点
			tree.pop();
			node_val.push_back(node->val);
			//如果输出节点有右子树，入栈右子树一次
			if (node->right)
				tree.push(node->right);

		}
		return node_val;
	}
};