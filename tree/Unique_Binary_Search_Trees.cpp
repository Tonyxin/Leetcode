/*
问题描述：
给n个数，一共可以生成多少个BST树（二叉排序树）

解决方法：
可以使用卡特兰数求解，设n个节点组成的BST树有a[n]个
如果1为root，则左子树有0个点，右子树有n-1个点，则此情况有BST树a[0]*a[n-1]个;
如果2为root，则左子树有1个点，右子树有n-2个点，则此情况有BST树a[1]*a[n-2]个;
如果3为root，则左子树有2个点，右子树有n-3个点，则此情况有BST树a[3]*a[n-3]个;
......
如果n为root，则左子树有n-1个点，右子树有0个点，则此情况有BST树a[n-1]*a[0]个;
so
a[n]=a[0]*a[n-1]+a[1]*a[n-2]+...+a[n-1]*a[0]，可递归求解
卡特兰数的通项是c(2n, n)/(n+1)
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
	int numTrees(int n) {
		if (!n)  return 0;
		vector<int> result(n + 1, 0);
		result[0] = 1;
		result[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			for (int j = 1; j <= i; j++)
				result[i] += result[j - 1] * result[i - j];
		}
		return result[n];
	}
};