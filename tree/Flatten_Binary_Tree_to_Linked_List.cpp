/*
问题描述：
将二叉树转为单向链表
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

解决方法：
1、右子树成为左子树最后遍历节点的右子树；
2、根节点的左子树变为右子树
3、将根节点的左子树变空
4、递归
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
			tmp->right = root->right;     //右子树成为左子树最后遍历节点的右子树
			root->right = root->left;     //根节点的左子树变为右子树
			root->left = NULL;            //将根节点的左子树变空
		}
		flatten(root->right);           //递归
	}
	//返回最后遍历的节点，程序的顺序是依据中序遍历顺序
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