/*
问题描述：
给定一个单向链表L和值x，使所有小于x的节点排在前面
For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
解决方法：
寻找第一个大于或等于x的节点，记为p;
在p之后寻找第一个小于x节点，记为q;
p→q之间的节点向右循环1次，由于是单向链表，不能直接找到前驱结点，采用赋值的方式
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
					int tmpdata = tmp->next->val;			//采用交换赋值的方式
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