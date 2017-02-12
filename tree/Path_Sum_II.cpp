/*
����������
Ѱ�ҴӸ���Ҷ�Ӻ͵��ڸ���ֵ��·��

���������
�����������������������µ�������
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
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> result;
		vector<int> single_result;
		recur(result, single_result, root, sum);
		return result;
	}
	void recur(vector<vector<int>>& result, vector<int> single_result, TreeNode* root, int sum)
	{
		if (!root)   return;
		single_result.push_back(root->val);
		sum = sum - (root->val);
		if (!sum&&!root->left&&!root->right)
		{
			result.push_back(single_result);
			return;
		}
		recur(result, single_result, root->left, sum);
		recur(result, single_result, root->right, sum);
	}
};