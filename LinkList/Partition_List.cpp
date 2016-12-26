/*
����������
����һ����������L��ֵx��ʹ����С��x�Ľڵ�����ǰ��
For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
���������
Ѱ�ҵ�һ�����ڻ����x�Ľڵ㣬��Ϊp;
��p֮��Ѱ�ҵ�һ��С��x�ڵ㣬��Ϊq;
p��q֮��Ľڵ�����ѭ��1�Σ������ǵ�����������ֱ���ҵ�ǰ����㣬���ø�ֵ�ķ�ʽ
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
	ListNode* partition(ListNode* head, int x) {
		if (!head || !head->next)  return head;
		auto p = head;
		while (p)
		{
			int val = p->val;
			if (val >= x)
			{
				auto q = firstSmall(p->next, x);
				if (!q)  break;
				for (auto tmp = p; tmp != q; tmp = tmp->next)
				{
					int tmpdata = tmp->next->val;			//���ý�����ֵ�ķ�ʽ
					tmp->next->val = val;
					val = tmpdata;
				}
				p->val = val;
			}
			p = p->next;
		}
		return head;
	}
private:
	ListNode* firstSmall(ListNode* head, int x)
	{
		if (!head)   return head;
		while (head)
		{
			if (head->val<x)
				break;
			head = head->next;
		}
		return head;
	}
};