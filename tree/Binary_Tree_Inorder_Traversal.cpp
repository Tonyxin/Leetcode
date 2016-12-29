/*
����������
���������������

���������
���õݹ�ķ�ʽ������ڵ�ݹ飬Ȼ��������ڵ㣬���ҽڵ�ݹ�
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
		recurTraversal(root, node_val);
		return node_val;
	}
private:
	void recurTraversal(TreeNode* root, vector<int> &node_val)
	{
		if (!root)   return;
		recurTraversal(root->left, node_val);				//�ȱ�����ڵ�
		node_val.push_back(root->val);						//������ڵ�ֵ
		recurTraversal(root->right, node_val);           //�ٱ����ҽڵ�
	}
};