/*
����������
�Զ�����ʵ�ֹ�����ȱ������������ڲ��ϱ�����˳���෴

���������
1����ÿһ�㱣�浽��ջ�У�����������
2����һ����ѹ����ڵ㣬��ѹ���ҽڵ㣻��һ��Ӧ����ѹ���ҽڵ㣬��ѹ����ڵ㣻
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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		if (!root)   return ans;
		stack<TreeNode*> stack_node;
		stack_node.push(root);
		bool order = 0;
		while (1)
		{
			order = (!order);
			vector<int> single_ans;
			stack<TreeNode*> new_stack;
			while (!stack_node.empty())
			{
				auto root = stack_node.top();
				single_ans.push_back(root->val);
				if (order)
				{
					if (root->left)  new_stack.push(root->left);
					if (root->right) new_stack.push(root->right);
				}
				else
				{
					if (root->right) new_stack.push(root->right);
					if (root->left)  new_stack.push(root->left);
				}
				stack_node.pop();
			}
			ans.push_back(single_ans);
			if (new_stack.empty())   break;
			stack_node = new_stack;
		}
		return ans;
	}
};