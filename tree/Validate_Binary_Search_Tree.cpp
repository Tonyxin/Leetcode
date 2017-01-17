/*
问题描述：
判断1个二叉树是否为BST

解决方法：
将树先序遍历，如果为BST，得到的必然为上升序列；如果不是上升序列，就不是BST
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
	bool isValidBST(TreeNode* root) {
		stack<TreeNode*> stack_tree;
		vector<TreeNode*> vector_tree;
		//线序遍历树，如果是二叉树,vector_tree必然是有序列
		if (!root)   return true;
		stack_tree.push(root);  //入栈根节点
		while (!stack_tree.empty())
		{
			root = stack_tree.top();
			//不断将左子树入栈
			while (root->left)
			{
				auto tmp = root;
				stack_tree.push(root->left);
				root = root->left;
				tmp->left = NULL;         //这里要去掉左子树
			}
			root = stack_tree.top();
			stack_tree.pop();
			vector_tree.push_back(root);    //输出节点
			if (root->right) stack_tree.push(root->right);//入栈右子树
		}
		for (auto itr = vector_tree.begin(); itr != vector_tree.end() - 1; itr++)
		if ((*itr)->val >= (*(itr + 1))->val)   return false;
		return true;
	}
};