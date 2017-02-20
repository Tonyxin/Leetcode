/*
����������
ʹ�ò�������Ե��������������

���������
Ѱ�Ҳ���λ�ã��½ڵ�Ӧ�ò����ڷ���ֵ�ĺ���
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
	//Ѱ�Ҳ���Ľڵ㣬�½ڵ�Ӧ�ò����ڷ���ֵ�ĺ���
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