/*
����������
��������������Ҫ��ʱ�临�Ӷ�ΪO(nlogn)���ռ临�Ӷ�ΪO(1);

���������
���úϲ�����
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
		//�������Ϊ����
		ListNode *slow = head, *fast = head->next;
		while (fast&&fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode* second = slow->next;
		slow->next = NULL;
		ListNode* first = head;
		//�ݹ飬�����½�����ֽ⣬���������κϲ�
		return merge(sortList(first), sortList(second));
	}
	//��������������ϲ�
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