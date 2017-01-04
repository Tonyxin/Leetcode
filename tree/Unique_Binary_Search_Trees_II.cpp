/*
问题描述：
给定数组1...n，返回所有可能的二叉树

解决方法：
动态（DP）规划问题，对于1..i得到的二叉树集合，在插入i+1时：
1、直接将i+1作为根节点；
2、将i+1插入右子树
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
				int length = result.size();           //动态规划问题，length在每次循环中都会变动
				for (int j = 0; j<length; j++)
				{
					//将第i个节点直接作为前面所有树的根节点
					TreeNode *node_i_1 = new TreeNode(i);
					node_i_1->left = cloneTree(result[j]);
					result.push_back(node_i_1);
					TreeNode *tmp = result[j];
					//将第i个节点插入到右子树
					while (tmp->right)
					{
						TreeNode *node_i_2 = new TreeNode(i);
						node_i_2->left = tmp->right;
						tmp->right = node_i_2;
						//这里要将树再拷贝一份
						result.push_back(cloneTree(result[j]));
						tmp->right = tmp->right->left;
						tmp = tmp->right;
						delete node_i_2;
						node_i_2 = NULL;
					}
					//将第i个节点作为最右节点
					TreeNode *node_i_2 = new TreeNode(i);
					tmp->right = node_i_2;
				}//for
			}//else
		}//for
		return result;
	}
private:
	//进行树的拷贝，并不是增加一个指针指向，而是值拷贝
	TreeNode* cloneTree(const TreeNode* src)
	{
		if (!src)    return NULL;
		TreeNode* target = new TreeNode(src->val);            //赋值节点
		target->left = cloneTree(src->left);                  //递归拷贝左子树
		target->right = cloneTree(src->right);                //递归拷贝右子树    
		return target;
	}
};