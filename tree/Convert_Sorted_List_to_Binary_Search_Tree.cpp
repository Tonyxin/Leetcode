/*
问题描述：
将一个有序单向链表L转为平衡二叉树T

解决方法：
L中间节点为二叉树的根节点，前后子序列分别转化为左右节点，进行递归
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
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
	TreeNode* sortedListToBST(ListNode* head) {
		return recur(head, NULL);
	}
	TreeNode* recur(ListNode* head, ListNode* tail) {
		if (head == tail)
			return NULL;
		int length = 0;
		ListNode* tmp = head;
		while (tmp != tail)
		{
			length++;
			tmp = tmp->next;
		}
		tmp = head;
		for (int i = 0; i<length / 2; i++) //获得中间元素，作为根节点
			tmp = tmp->next;
		TreeNode* root = new TreeNode(tmp->val);
		root->left = recur(head, tmp);
		root->right = recur(tmp->next, tail);
		return root;
	}
};