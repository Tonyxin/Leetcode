/*
问题描述：
将单项链表排序，要求时间复杂度为O(nlogn)，空间复杂度为O(1);

解决方法：
采用合并排序
*/
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (!head || !head->next)  return head;
		//将链表分为两半
		ListNode *slow = head, *fast = head->next;
		while (fast&&fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode* second = slow->next;
		slow->next = NULL;
		ListNode* first = head;
		//递归，先向下将链表分解，在向上依次合并
		return merge(sortList(first), sortList(second));
	}
	//将两个有序链表合并
	ListNode* merge(ListNode* first, ListNode* second)
	{
		if (!first || !second)
			return first ? first : second;
		ListNode *l1 = first, *l2 = second, *tmp;
		if (l1->val<l2->val)
		{
			while (l1&&l2)
			{
				while (l1&&l2&&l1->next&&l1->next->val<l2->val)
					l1 = l1->next;
				if (l2)
				{
					tmp = l1->next;
					l1->next = l2;
					l1 = tmp;
				}
				while (l1&&l2&&l2->next&&l2->next->val<l1->val)
					l2 = l2->next;
				if (l1)
				{
					tmp = l2->next;
					l2->next = l1;
					l2 = tmp;
				}
			}
			return first;
		}
		else
		{
			while (l1&&l2)
			{
				while (l1&&l2&&l2->next&&l2->next->val<l1->val)
					l2 = l2->next;
				if (l1)
				{
					tmp = l2->next;
					l2->next = l1;
					l2 = tmp;
				}
				while (l1&&l2&&l1->next&&l1->next->val<l2->val)
					l1 = l1->next;
				if (l2)
				{
					tmp = l1->next;
					l1->next = l2;
					l1 = tmp;
				}
			}
			return second;
		}//else
	}//if
};