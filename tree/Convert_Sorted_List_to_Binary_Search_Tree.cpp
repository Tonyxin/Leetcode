/*
����������
��һ������������LתΪƽ�������T

���������
L�м�ڵ�Ϊ�������ĸ��ڵ㣬ǰ�������зֱ�ת��Ϊ���ҽڵ㣬���еݹ�
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
		for (int i = 0; i<length / 2; i++) //����м�Ԫ�أ���Ϊ���ڵ�
			tmp = tmp->next;
		TreeNode* root = new TreeNode(tmp->val);
		root->left = recur(head, tmp);
		root->right = recur(tmp->next, tail);
		return root;
	}
};