/*
问题描述：
对二叉树实现广度优先遍历，但在相邻层上遍历的顺序相反

解决方法：
1、将每一层保存到堆栈中，反反得正；
2、上一层先压入左节点，后压入右节点；下一层应该先压入右节点，再压入左节点；
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