/*
问题描述：
二叉树的先序遍历

解决方法：
采用递归的方式，先左节点递归，然后输出根节点，再右节点递归
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
		recurTraversal(root, node_val);
		return node_val;
	}
private:
	void recurTraversal(TreeNode* root, vector<int> &node_val)
	{
		if (!root)   return;
		recurTraversal(root->left, node_val);				//先遍历左节点
		node_val.push_back(root->val);						//输出根节点值
		recurTraversal(root->right, node_val);           //再遍历右节点
	}
};