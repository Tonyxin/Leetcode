/*
����������
��n������һ���������ɶ��ٸ�BST����������������

���������
����ʹ�ÿ���������⣬��n���ڵ���ɵ�BST����a[n]��
���1Ϊroot������������0���㣬��������n-1���㣬��������BST��a[0]*a[n-1]��;
���2Ϊroot������������1���㣬��������n-2���㣬��������BST��a[1]*a[n-2]��;
���3Ϊroot������������2���㣬��������n-3���㣬��������BST��a[3]*a[n-3]��;
......
���nΪroot������������n-1���㣬��������0���㣬��������BST��a[n-1]*a[0]��;
so
a[n]=a[0]*a[n-1]+a[1]*a[n-2]+...+a[n-1]*a[0]���ɵݹ����
����������ͨ����c(2n, n)/(n+1)
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