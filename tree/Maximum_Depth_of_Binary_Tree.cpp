/*
问题描述：
求一个二叉树的最大深度

解决方法：
为max(左子树深度，右子树深度)+1
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
	int maxDepth(TreeNode* root) {
		return root == NULL ? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};