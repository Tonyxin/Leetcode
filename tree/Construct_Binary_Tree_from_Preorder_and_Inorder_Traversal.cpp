/*
����������
���������������й��������

���������
��������inorder�е�һ����a������ȷ��root(a)��
Ѱ��a����������preorder�е�λ�ã�
��������preorder�У�a���Ϊ����������a�ұ�Ϊ����������
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