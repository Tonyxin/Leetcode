/*
����������
���������������

���������
���÷ǵݹ�ķ�ʽ�����ö�ջ�ķ�ʽ����ڵ�
����������ȱ�����������������ڵ㣬�ٱ���������
���ö�ջ��
1����������һֱ��ջ��
2��Ȼ������ڵ㣬����Ľڵ����������������ջһ��������
3������2�Ľ�����ظ�1
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
			//������������ջ
			while (node->left)
			{
				tree.push(node->left);
				//ע�������������ջ�Ľڵ�(ջ��δ���)��Ӧ��ȥ�����ӹ�ϵ
				//���򣬿��ܵ�����ѭ��
				auto tmp = node;
				node = node->left;
				tmp->left = NULL;
			}
			node = tree.top();
			//����ڵ�
			tree.pop();
			node_val.push_back(node->val);
			//�������ڵ�������������ջ������һ��
			if (node->right)
				tree.push(node->right);

		}
		return node_val;
	}
};