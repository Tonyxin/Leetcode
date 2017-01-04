/*
����������
��������1...n���������п��ܵĶ�����

���������
��̬��DP���滮���⣬����1..i�õ��Ķ��������ϣ��ڲ���i+1ʱ��
1��ֱ�ӽ�i+1��Ϊ���ڵ㣻
2����i+1����������
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
	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> result;
		for (int i = 1; i <= n; i++)
		{
			if (i == 1)
			{
				TreeNode *node_i = new TreeNode(i);
				result.push_back(node_i);
			}
			else
			{
				int length = result.size();           //��̬�滮���⣬length��ÿ��ѭ���ж���䶯
				for (int j = 0; j<length; j++)
				{
					//����i���ڵ�ֱ����Ϊǰ���������ĸ��ڵ�
					TreeNode *node_i_1 = new TreeNode(i);
					node_i_1->left = cloneTree(result[j]);
					result.push_back(node_i_1);
					TreeNode *tmp = result[j];
					//����i���ڵ���뵽������
					while (tmp->right)
					{
						TreeNode *node_i_2 = new TreeNode(i);
						node_i_2->left = tmp->right;
						tmp->right = node_i_2;
						//����Ҫ�����ٿ���һ��
						result.push_back(cloneTree(result[j]));
						tmp->right = tmp->right->left;
						tmp = tmp->right;
						delete node_i_2;
						node_i_2 = NULL;
					}
					//����i���ڵ���Ϊ���ҽڵ�
					TreeNode *node_i_2 = new TreeNode(i);
					tmp->right = node_i_2;
				}//for
			}//else
		}//for
		return result;
	}
private:
	//�������Ŀ���������������һ��ָ��ָ�򣬶���ֵ����
	TreeNode* cloneTree(const TreeNode* src)
	{
		if (!src)    return NULL;
		TreeNode* target = new TreeNode(src->val);            //��ֵ�ڵ�
		target->left = cloneTree(src->left);                  //�ݹ鿽��������
		target->right = cloneTree(src->right);                //�ݹ鿽��������    
		return target;
	}
};