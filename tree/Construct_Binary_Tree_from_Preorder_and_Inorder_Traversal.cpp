/*
问题描述：
从先序和中序遍历中构造二叉树

解决方法：
中序序列inorder中第一个数a，可以确定root(a)；
寻找a在先序序列preorder中的位置；
先序序列preorder中，a左边为其左子树，a右边为其右子树；
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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int length = preorder.size();
		if (!length) return NULL;
		return recur(preorder,0,length,inorder,0,length);
	}
public:
	TreeNode* recur(vector<int>& preorder, int p_fp, int p_lp, vector<int>& inorder, int i_fp, int i_lp)
	{
		if (p_fp == p_lp)  return NULL;
		int i, j;
		bool pos_is_found = 0;
		for (i = i_fp; i != i_lp; i++)
		{
			for (j = p_fp; j != p_lp; j++)
			{
				if (preorder[j] == inorder[i])
				{
					pos_is_found = 1;
					break;
				}//if
			}//for
			if (pos_is_found) break;
		}//for
		TreeNode *root = new TreeNode(preorder[j]);
		root->left = recur(preorder, p_fp, j, inorder, i + 1, i_lp);
		root->right = recur(preorder, j + 1, p_lp, inorder, i + 1, i_lp);
		return root;
	}

};