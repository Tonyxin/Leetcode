/*
����������
�ж�1���������Ƿ�ΪBST

���������
����������������ΪBST���õ��ı�ȻΪ�������У���������������У��Ͳ���BST
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
		//���������������Ƕ�����,vector_tree��Ȼ��������
		if (!root)   return true;
		stack_tree.push(root);  //��ջ���ڵ�
		while (!stack_tree.empty())
		{
			root = stack_tree.top();
			//���Ͻ���������ջ
			while (root->left)
			{
				auto tmp = root;
				stack_tree.push(root->left);
				root = root->left;
				tmp->left = NULL;         //����Ҫȥ��������
			}
			root = stack_tree.top();
			stack_tree.pop();
			vector_tree.push_back(root);    //����ڵ�
			if (root->right) stack_tree.push(root->right);//��ջ������
		}
		for (auto itr = vector_tree.begin(); itr != vector_tree.end() - 1; itr++)
		if ((*itr)->val >= (*(itr + 1))->val)   return false;
		return true;
	}
};