/*
问题描述：
使用插入排序对单向链表进行排序

解决方法：
寻找插入位置，新节点应该插入在返回值的后面
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
	ListNode* insertionSortList(ListNode* head) {
		if (!head || !head->next)
			return head;
		ListNode* itr = head->next;
		head->next = NULL;
		while (itr)
		{
			ListNode* tmp = itr->next;
			if ((itr->val)<(head->val))
			{
				itr->next = head;
				head = itr;
			}
			else
			{
				ListNode* pos = searchPos(head, itr->val);
				itr->next = pos->next;
				pos->next = itr;
			}
			itr = tmp;
		}
		return head;
	}
	//寻找插入的节点，新节点应该插入在返回值的后面
	ListNode* searchPos(ListNode* head, int val)
	{
		while (head->next)
		{
			if (head->next->val>val)
				break;
			head = head->next;
		}
		return head;
	}
};