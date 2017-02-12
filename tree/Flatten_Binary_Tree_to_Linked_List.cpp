/*
����������
��������תΪ��������
For example,
Given

                         1
                        / \
                      2    5
                     /  \    \
                   3    4    6
The flattened tree should look like:
1
 \
  2
    \
     3
	   \
	    4
		  \
			5
			  \
			    6

���������
1����������Ϊ�������������ڵ����������
2�����ڵ����������Ϊ������
3�������ڵ�����������
4���ݹ�
	  1
     / \
   2    5
  /  \     \
3     4     6
      
	  1								       1														1
     /										     \														   \
   2											  2														 2
  /  \				->						/	 \							->						/				->....
3     4									  3	   4												  3		
         \												  \													 \
		   5												5												   4
		     \												  \													  \
			   6												6													5
																													   \
																														6
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
	void flatten(TreeNode* root) {
		if (!root)   return;
		if (root->left)
		{
			TreeNode* tmp = SearchLastNode(root->left);
			tmp->right = root->right;     //��������Ϊ�������������ڵ��������
			root->right = root->left;     //���ڵ����������Ϊ������
			root->left = NULL;            //�����ڵ�����������
		}
		flatten(root->right);           //�ݹ�
	}
	//�����������Ľڵ㣬�����˳���������������˳��
	TreeNode* SearchLastNode(TreeNode* root)
	{
		if (!root->left&&!root->right)
			return root;
		if (root->right)
			return SearchLastNode(root->right);
		if (root->left)
			return SearchLastNode(root->left);
	}
};